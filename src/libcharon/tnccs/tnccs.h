/*
 * Copyright (C) 2010 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
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

/**
 * @defgroup tnccs tnccs
 * @{ @ingroup libcharon
 */

#ifndef TNCCS_H_
#define TNCCS_H_

typedef enum tnccs_type_t tnccs_type_t;

#include <library.h>

/**
 * Type of TNC Client/Server protocol
 */
enum tnccs_type_t {
	TNCCS_1_1,
	TNCCS_SOH,
	TNCCS_2_0
};

/**
 * enum names for tnccs_type_t.
 */
extern enum_name_t *tnccs_type_names;

typedef struct tnccs_t tnccs_t;

/**
 * Constructor definition for a pluggable TNCCS protocol implementation.
 *
 * @param is_server		TRUE if TNC Server, FALSE if TNC Client
 * @return				implementation of the tnccs_t interface
 */
typedef tnccs_t* (*tnccs_constructor_t)(bool is_server);

#endif /** TNC_H_ @}*/
