/*
 * Copyright (C) 2007 Martin Willi
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

#include <asn1/oid.h>

#include "public_key.h"

ENUM(key_type_names, KEY_RSA, KEY_DSA,
	"RSA",
	"ECDSA",
	"DSA"
);

ENUM(signature_scheme_names, SIGN_UNKNOWN, SIGN_ECDSA_521,
	"UNKNOWN",
	"RSA_EMSA_PKCS1_NULL",
	"RSA_EMSA_PKCS1_MD5",
	"RSA_EMSA_PKCS1_SHA1",
	"RSA_EMSA_PKCS1_SHA256",
	"RSA_EMSA_PKCS1_SHA384",
	"RSA_EMSA_PKCS1_SHA512",
	"ECDSA_WITH_NULL",
	"ECDSA_WITH_SHA1",
	"ECDSA-256",
	"ECDSA-384",
	"ECDSA-521",
);

/*
 * Defined in header.
 */
signature_scheme_t signature_scheme_from_oid(int oid)
{
	switch (oid)
	{
		case OID_MD5_WITH_RSA:
		case OID_MD5:
			return SIGN_RSA_EMSA_PKCS1_MD5;
		case OID_SHA1_WITH_RSA:
		case OID_SHA1:
			return SIGN_RSA_EMSA_PKCS1_SHA1;
		case OID_SHA256_WITH_RSA:
		case OID_SHA256:
			return SIGN_RSA_EMSA_PKCS1_SHA256;
		case OID_SHA384_WITH_RSA:
		case OID_SHA384:
			return SIGN_RSA_EMSA_PKCS1_SHA384;
		case OID_SHA512_WITH_RSA:
		case OID_SHA512:
			return SIGN_RSA_EMSA_PKCS1_SHA512;
		case OID_ECDSA_WITH_SHA1:
		case OID_EC_PUBLICKEY:
			return SIGN_ECDSA_WITH_SHA1;
		default:
			return SIGN_UNKNOWN;
	}
}

