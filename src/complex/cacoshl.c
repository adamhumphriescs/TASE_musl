#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex cacoshl(TASELDOUBLE complex z)
{
	return cacosh(z);
}
#else
TASELDOUBLE complex cacoshl(TASELDOUBLE complex z)
{
	z = cacosl(z);
	return CMPLXL(-cimagl(z), creall(z));
}
#endif
