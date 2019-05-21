#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE fabsl(TASELDOUBLE x)
{
	return fabs(x);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
TASELDOUBLE fabsl(TASELDOUBLE x)
{
	union ldshape u = {x};

	u.i.se &= 0x7fff;
	return u.f;
}
#endif
