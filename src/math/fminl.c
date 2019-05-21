#include <math.h>
#include <float.h>

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
TASELDOUBLE fminl(TASELDOUBLE x, TASELDOUBLE y)
{
	return fmin(x, y);
}
#else
TASELDOUBLE fminl(TASELDOUBLE x, TASELDOUBLE y)
{
	if (isnan(x))
		return y;
	if (isnan(y))
		return x;
	/* handle signed zeros, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y))
		return signbit(x) ? x : y;
	return x < y ? x : y;
}
#endif
