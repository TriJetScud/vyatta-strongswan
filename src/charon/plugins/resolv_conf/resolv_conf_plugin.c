/*
 * Copyright (C) 2009 Martin Willi
 * Hochschule fuer Technik Rapperswil
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

#include "resolv_conf_plugin.h"
#include "resolv_conf_handler.h"

#include <daemon.h>

typedef struct private_resolv_conf_plugin_t private_resolv_conf_plugin_t;

/**
 * private data of resolv_conf plugin
 */
struct private_resolv_conf_plugin_t {

	/**
	 * implements plugin interface
	 */
	resolv_conf_plugin_t public;
	
	/**
	 * The registerd DNS attribute handler
	 */
	resolv_conf_handler_t *handler;
};

/**
 * Implementation of plugin_t.destroy
 */
static void destroy(private_resolv_conf_plugin_t *this)
{
	charon->attributes->remove_handler(charon->attributes,
									   &this->handler->handler);
	this->handler->destroy(this->handler);
	free(this);
}

/*
 * see header file
 */
plugin_t *plugin_create()
{
	private_resolv_conf_plugin_t *this = malloc_thing(private_resolv_conf_plugin_t);
	
	this->public.plugin.destroy = (void(*)(plugin_t*))destroy;
	
	this->handler = resolv_conf_handler_create();
	charon->attributes->add_handler(charon->attributes, &this->handler->handler);
	
	return &this->public.plugin;
}

