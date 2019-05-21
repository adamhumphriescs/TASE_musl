#include <features.h>

/* shared by acosl, asinl and atan2l */
#define pio2_hi __pio2_hi
#define pio2_lo __pio2_lo
hidden extern const TASELDOUBLE pio2_hi, pio2_lo;

hidden TASELDOUBLE __invtrigl_R(TASELDOUBLE z);
