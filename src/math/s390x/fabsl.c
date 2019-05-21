#include <math.h>

#if defined(__HTM__) || __ARCH__ >= 9

TASELDOUBLE fabsl(TASELDOUBLE x)
{
	__asm__ ("lpxbr %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../fabsl.c"

#endif
