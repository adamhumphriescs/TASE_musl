#include <math.h>
#include <float.h>

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE remainderl(TASELDOUBLE x, TASELDOUBLE y)
{
	return remainder(x, y);
}
#else
TASELDOUBLE remainderl(TASELDOUBLE x, TASELDOUBLE y)
{
	int q;
	return remquol(x, y, &q);
}
#endif
