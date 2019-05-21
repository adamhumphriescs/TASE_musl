#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex cprojl(TASELDOUBLE complex z)
{
	return cproj(z);
}
#else
TASELDOUBLE complex cprojl(TASELDOUBLE complex z)
{
	if (isinf(creall(z)) || isinf(cimagl(z)))
		return CMPLXL(INFINITY, copysignl(0.0, creall(z)));
	return z;
}
#endif
