#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE cargl(TASELDOUBLE complex z)
{
	return carg(z);
}
#else
TASELDOUBLE cargl(TASELDOUBLE complex z)
{
	return atan2l(cimagl(z), creall(z));
}
#endif
