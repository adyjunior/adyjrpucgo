/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "simp.h"
#define foo 127

bool_t
xdr_operands (XDR *xdrs, operands *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->x))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->y))
		 return FALSE;
	return TRUE;
}