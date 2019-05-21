#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex cpowl(TASELDOUBLE complex z, TASELDOUBLE complex c)
{
	return cpow(z, c);
}
#else
TASELDOUBLE complex cpowl(TASELDOUBLE complex z, TASELDOUBLE complex c)
{
	return cexpl(c * clogl(z));
}
#endif
