#include "complex_impl.h"

TASELDOUBLE complex conjl(TASELDOUBLE complex z)
{
	return CMPLXL(creall(z), -cimagl(z));
}
