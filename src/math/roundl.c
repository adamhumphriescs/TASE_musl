#include "libm.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE roundl(TASELDOUBLE x)
{
	return round(x);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384

static const TASELDOUBLE toint = 1/LDBL_EPSILON;

TASELDOUBLE roundl(TASELDOUBLE x)
{
	union ldshape u = {x};
	int e = u.i.se & 0x7fff;
	TASELDOUBLE y;

	if (e >= 0x3fff+LDBL_MANT_DIG-1)
		return x;
	if (u.i.se >> 15)
		x = -x;
	if (e < 0x3fff-1) {
		FORCE_EVAL(x + toint);
		return 0*u.f;
	}
	y = x + toint - toint - x;
	if (y > 0.5)
		y = y + x - 1;
	else if (y <= -0.5)
		y = y + x + 1;
	else
		y = y + x;
	if (u.i.se >> 15)
		y = -y;
	return y;
}
#endif
