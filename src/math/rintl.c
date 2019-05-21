#include "libm.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE rintl(TASELDOUBLE x)
{
	return rint(x);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384

static const TASELDOUBLE toint = 1/LDBL_EPSILON;

TASELDOUBLE rintl(TASELDOUBLE x)
{
	union ldshape u = {x};
	int e = u.i.se & 0x7fff;
	int s = u.i.se >> 15;
	TASELDOUBLE y;

	if (e >= 0x3fff+LDBL_MANT_DIG-1)
		return x;
	if (s)
		y = x - toint + toint;
	else
		y = x + toint - toint;
	if (y == 0)
		return 0*x;
	return y;
}
#endif
