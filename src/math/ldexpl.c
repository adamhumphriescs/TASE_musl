#include <math.h>

TASELDOUBLE ldexpl(TASELDOUBLE x, int n)
{
	return scalbnl(x, n);
}
