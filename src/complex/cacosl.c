#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex cacosl(TASELDOUBLE complex z)
{
	return cacos(z);
}
#else
// FIXME
#define PI_2 1.57079632679489661923132169163975144L
TASELDOUBLE complex cacosl(TASELDOUBLE complex z)
{
	z = casinl(z);
	return CMPLXL(PI_2 - creall(z), -cimagl(z));
}
#endif
