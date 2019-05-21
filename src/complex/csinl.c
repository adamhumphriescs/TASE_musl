#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex csinl(TASELDOUBLE complex z)
{
	return csin(z);
}
#else
TASELDOUBLE complex csinl(TASELDOUBLE complex z)
{
	z = csinhl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(z), -creall(z));
}
#endif
