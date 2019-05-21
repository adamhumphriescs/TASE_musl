#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex ctanl(TASELDOUBLE complex z)
{
	return ctan(z);
}
#else
TASELDOUBLE complex ctanl(TASELDOUBLE complex z)
{
	z = ctanhl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(z), -creall(z));
}
#endif
