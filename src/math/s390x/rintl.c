#include <math.h>

#if defined(__HTM__) || __ARCH__ >= 9

TASELDOUBLE rintl(TASELDOUBLE x)
{
	__asm__ ("fixbr %0, 0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../rintl.c"

#endif
