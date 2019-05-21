#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE complex casinl(TASELDOUBLE complex z)
{
	return casin(z);
}
#else
// FIXME
TASELDOUBLE complex casinl(TASELDOUBLE complex z)
{
	TASELDOUBLE complex w;
	TASELDOUBLE x, y;

	x = creall(z);
	y = cimagl(z);
	w = CMPLXL(1.0 - (x - y)*(x + y), -2.0*x*y);
	TASELDOUBLE complex r = clogl(CMPLXL(-y, x) + csqrtl(w));
	return CMPLXL(cimagl(r), -creall(r));
}
#endif
