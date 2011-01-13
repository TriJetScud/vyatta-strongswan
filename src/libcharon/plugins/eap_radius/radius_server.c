/*
 * Copyright (C) 2010 Martin Willi
 * Copyright (C) 2010 revosec AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include "radius_server.h"

#include <threading/mutex.h>
#include <threading/condvar.h>
#include <utils/linked_list.h>

typedef struct private_radius_server_t private_radius_server_t;

/**
 * Private data of an radius_server_t object.
 */
struct private_radius_server_t {

	/**
	 * Public radius_server_t interface.
	 */
	radius_server_t public;

	/**
	 * RADIUS server address
	 */
	host_t *host;

	/**
	 * list of radius sockets, as radius_socket_t
	 */
	linked_list_t *sockets;

	/**
	 * Total number of sockets, in list + currently in use
	 */
	int socket_count;

	/**
	 * mutex to lock sockets list
	 */
	mutex_t *mutex;

	/**
	 * condvar to wait for sockets
	 */
	condvar_t *condvar;

	/**
	 * RADIUS secret
	 */
	chunk_t secret;

	/**
	 * NAS-Identifier
	 */
	chunk_t nas_identifier;

	/**
	 * Preference boost for this server
	 */
	int preference;

	/**
	 * Is the server currently reachable
	 */
	bool reachable;

	/**
	 * Retry counter for unreachable servers
	 */
	int retry;
};

METHOD(radius_server_t, get_socket, radius_socket_t*,
	private_radius_server_t *this)
{
	radius_socket_t *skt;

	this->mutex->lock(this->mutex);
	while (this->sockets->remove_first(this->sockets, (void**)&skt) != SUCCESS)
	{
		this->condvar->wait(this->condvar, this->mutex);
	}
	this->mutex->unlock(this->mutex);
	return skt;
}

METHOD(radius_server_t, put_socket, void,
	private_radius_server_t *this, radius_socket_t *skt, bool result)
{
	this->mutex->lock(this->mutex);
	this->sockets->insert_last(this->sockets, skt);
	this->mutex->unlock(this->mutex);
	this->condvar->signal(this->condvar);
	this->reachable = result;
}

METHOD(radius_server_t, get_nas_identifier, chunk_t,
	private_radius_server_t *this)
{
	return this->nas_identifier;
}

METHOD(radius_server_t, get_preference, int,
	private_radius_server_t *this)
{
	int pref;

	if (this->socket_count == 0)
	{	/* don't have sockets, huh? */
		return -1;
	}
	/* calculate preference between 0-100 + boost */
	pref = this->preference;
	pref += this->sockets->get_count(this->sockets) * 100 / this->socket_count;
	if (this->reachable)
	{	/* reachable server get a boost: pref = 110-210 + boost */
		return pref + 110;
	}
	/* Not reachable. Increase preference randomly to let it retry from
	 * time to time, especially if other servers have high load. */
	this->retry++;
	if (this->retry % 128 == 0)
	{	/* every 64th request gets 210, same as unloaded reachable */
		return pref + 110;
	}
	if (this->retry % 32 == 0)
	{	/* every 32th request gets 190, wins against average loaded */
		return pref + 90;
	}
	if (this->retry % 8 == 0)
	{	/* every 8th request gets 110, same as server under load */
		return pref + 10;
	}
	/* other get ~100, less than fully loaded */
	return pref;
}

METHOD(radius_server_t, get_address, host_t*,
	private_radius_server_t *this)
{
	return this->host;
}

METHOD(radius_server_t, destroy, void,
	private_radius_server_t *this)
{
	DESTROY_IF(this->host);
	this->mutex->destroy(this->mutex);
	this->condvar->destroy(this->condvar);
	this->sockets->destroy_offset(this->sockets,
								  offsetof(radius_socket_t, destroy));
	free(this);
}

/**
 * See header
 */
radius_server_t *radius_server_create(char *server, u_int16_t port,
				char *nas_identifier, char *secret, int sockets, int preference)
{
	private_radius_server_t *this;
	radius_socket_t *socket;

	INIT(this,
		.public = {
			.get_socket = _get_socket,
			.put_socket = _put_socket,
			.get_nas_identifier = _get_nas_identifier,
			.get_preference = _get_preference,
			.get_address = _get_address,
			.destroy = _destroy,
		},
		.reachable = TRUE,
		.nas_identifier = chunk_create(nas_identifier, strlen(nas_identifier)),
		.socket_count = sockets,
		.sockets = linked_list_create(),
		.mutex = mutex_create(MUTEX_TYPE_DEFAULT),
		.condvar = condvar_create(CONDVAR_TYPE_DEFAULT),
		.host = host_create_from_dns(server, 0, port),
		.preference = preference,
	);

	if (!this->host)
	{
		destroy(this);
		return NULL;
	}
	while (sockets--)
	{
		socket = radius_socket_create(this->host,
									  chunk_create(secret, strlen(secret)));
		if (!socket)
		{
			destroy(this);
			return NULL;
		}
		this->sockets->insert_last(this->sockets, socket);
	}
	return &this->public;
}
