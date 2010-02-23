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

#include "pgp_encoder.h"

#include <debug.h>

/**
 * Build a PGPv3 fingerprint
 */
static bool build_v3_fingerprint(chunk_t *encoding, va_list args)
{
	hasher_t *hasher;
	chunk_t n, e;

	if (key_encoding_args(args, KEY_PART_RSA_MODULUS, &n,
						  KEY_PART_RSA_PUB_EXP, &e, KEY_PART_END))
	{
		hasher = lib->crypto->create_hasher(lib->crypto, HASH_MD5);
		if (!hasher)
		{
			DBG1("MD5 hash algorithm not supported, PGP fingerprinting failed");
			return FALSE;
		}
		/* remove leading zero bytes before hashing modulus and exponent */
		while (n.len > 0 && n.ptr[0] == 0x00)
		{
			n = chunk_skip(n, 1);
		}
		while (e.len > 0 && e.ptr[0] == 0x00)
		{
			e = chunk_skip(e, 1);
		}
		hasher->allocate_hash(hasher, n, NULL);
		hasher->allocate_hash(hasher, e, encoding);
		hasher->destroy(hasher);
		return TRUE;
	}
	return FALSE;
}

/**
 * See header.
 */
bool pgp_encoder_encode(key_encoding_type_t type, chunk_t *encoding,
						  va_list args)
{
	switch (type)
	{
		case KEY_ID_PGPV3:
			return build_v3_fingerprint(encoding, args);
		default:
			return FALSE;
	}
}

