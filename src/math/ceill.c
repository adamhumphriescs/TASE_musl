#include "libm.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE ceill(TASELDOUBLE x)
{
	return ceil(x);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384

static const TASELDOUBLE toint = 1/LDBL_EPSILON;

TASELDOUBLE ceill(TASELDOUBLE x)
{
	union ldshape u = {x};
	int e = u.i.se & 0x7fff;
	TASELDOUBLE y;

	if (e >= 0x3fff+LDBL_MANT_DIG-1 || x == 0)
		return x;
	/* y = int(x) - x, where int(x) is an integer neighbor of x */
	if (u.i.se >> 15)
		y = x - toint + toint - x;
	else
		y = x + toint - toint - x;
	/* special case because of non-nearest rounding modes */
	if (e <= 0x3fff-1) {
		FORCE_EVAL(y);
		return u.i.se >> 15 ? -0.0 : 1;
	}
	if (y < 0)
		return x + y + 1;
	return x + y;
}
#endif
