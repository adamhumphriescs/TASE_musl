#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex ccosl(TASELDOUBLE complex z)
{
	return ccos(z);
}
#else
TASELDOUBLE complex ccosl(TASELDOUBLE complex z)
{
	return ccoshl(CMPLXL(-cimagl(z), creall(z)));
}
#endif
