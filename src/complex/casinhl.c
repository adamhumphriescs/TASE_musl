#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex casinhl(TASELDOUBLE complex z)
{
	return casinh(z);
}
#else
TASELDOUBLE complex casinhl(TASELDOUBLE complex z)
{
	z = casinl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(z), -creall(z));
}
#endif
