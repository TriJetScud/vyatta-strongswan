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

#include "tncifimv.h"

ENUM(TNC_IMV_Action_Recommendation_names,
	TNC_IMV_ACTION_RECOMMENDATION_ALLOW,
	TNC_IMV_ACTION_RECOMMENDATION_NO_RECOMMENDATION,
	"allow",
	"no access",
	"isolate",
	"no recommendation"
);

ENUM(TNC_IMV_Evaluation_Result_names,
	TNC_IMV_EVALUATION_RESULT_COMPLIANT,
	TNC_IMV_EVALUATION_RESULT_DONT_KNOW,
	"compliant",
	"non-compliant minor",
	"non-compliant major",
	"error",
	"don't know"
);

