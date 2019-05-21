#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex clogl(TASELDOUBLE complex z)
{
	return clog(z);
}
#else
// FIXME
TASELDOUBLE complex clogl(TASELDOUBLE complex z)
{
	TASELDOUBLE r, phi;

	r = cabsl(z);
	phi = cargl(z);
	return CMPLXL(logl(r), phi);
}
#endif
