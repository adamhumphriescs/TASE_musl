#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE cabsl(TASELDOUBLE complex z)
{
	return cabs(z);
}
#else
TASELDOUBLE cabsl(TASELDOUBLE complex z)
{
	return hypotl(creall(z), cimagl(z));
}
#endif
