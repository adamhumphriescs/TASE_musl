#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex catanhl(TASELDOUBLE complex z)
{
	return catanh(z);
}
#else
TASELDOUBLE complex catanhl(TASELDOUBLE complex z)
{
	z = catanl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(z), -creall(z));
}
#endif
