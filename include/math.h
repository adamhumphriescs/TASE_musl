#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_float_t
#define __NEED_double_t
#include <bits/alltypes.h>

#if 100*__GNUC__+__GNUC_MINOR__ >= 303
#define NAN       __builtin_nanf("")
#define INFINITY  __builtin_inff()
#else
#define NAN       (0.0f/0.0f)
#define INFINITY  1e5000f
#endif

#define HUGE_VALF INFINITY
#define HUGE_VAL  ((double)INFINITY)
#define HUGE_VALL ((TASELDOUBLE)INFINITY)

#define MATH_ERRNO  1
#define MATH_ERREXCEPT 2
#define math_errhandling 2

#define FP_ILOGBNAN (-1-0x7fffffff)
#define FP_ILOGB0 FP_ILOGBNAN

#define FP_NAN       0
#define FP_INFINITE  1
#define FP_ZERO      2
#define FP_SUBNORMAL 3
#define FP_NORMAL    4

#ifdef __FP_FAST_FMA
#define FP_FAST_FMA 1
#endif

#ifdef __FP_FAST_FMAF
#define FP_FAST_FMAF 1
#endif

#ifdef __FP_FAST_FMAL
#define FP_FAST_FMAL 1
#endif

int __fpclassify(double);
int __fpclassifyf(float);
int __fpclassifyl(TASELDOUBLE);

static __inline unsigned __FLOAT_BITS(float __f)
{
	union {float __f; unsigned __i;} __u;
	__u.__f = __f;
	return __u.__i;
}
static __inline unsigned long long __DOUBLE_BITS(double __f)
{
	union {double __f; unsigned long long __i;} __u;
	__u.__f = __f;
	return __u.__i;
}

#define fpclassify(x) ( \
	sizeof(x) == sizeof(float) ? __fpclassifyf(x) : \
	sizeof(x) == sizeof(double) ? __fpclassify(x) : \
	__fpclassifyl(x) )

#define isinf(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) == 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) == 0x7ffULL<<52 : \
	__fpclassifyl(x) == FP_INFINITE)

#define isnan(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) > 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) > 0x7ffULL<<52 : \
	__fpclassifyl(x) == FP_NAN)

#define isnormal(x) ( \
	sizeof(x) == sizeof(float) ? ((__FLOAT_BITS(x)+0x00800000) & 0x7fffffff) >= 0x01000000 : \
	sizeof(x) == sizeof(double) ? ((__DOUBLE_BITS(x)+(1ULL<<52)) & -1ULL>>1) >= 1ULL<<53 : \
	__fpclassifyl(x) == FP_NORMAL)

#define isfinite(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) < 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) < 0x7ffULL<<52 : \
	__fpclassifyl(x) > FP_INFINITE)

int __signbit(double);
int __signbitf(float);
int __signbitl(TASELDOUBLE);

#define signbit(x) ( \
	sizeof(x) == sizeof(float) ? (int)(__FLOAT_BITS(x)>>31) : \
	sizeof(x) == sizeof(double) ? (int)(__DOUBLE_BITS(x)>>63) : \
	__signbitl(x) )

#define isunordered(x,y) (isnan((x)) ? ((void)(y),1) : isnan((y)))

#define __ISREL_DEF(rel, op, type) \
static __inline int __is##rel(type __x, type __y) \
{ return !isunordered(__x,__y) && __x op __y; }

__ISREL_DEF(lessf, <, float_t)
__ISREL_DEF(less, <, double_t)
__ISREL_DEF(lessl, <, TASELDOUBLE)
__ISREL_DEF(lessequalf, <=, float_t)
__ISREL_DEF(lessequal, <=, double_t)
__ISREL_DEF(lessequall, <=, TASELDOUBLE)
__ISREL_DEF(lessgreaterf, !=, float_t)
__ISREL_DEF(lessgreater, !=, double_t)
__ISREL_DEF(lessgreaterl, !=, TASELDOUBLE)
__ISREL_DEF(greaterf, >, float_t)
__ISREL_DEF(greater, >, double_t)
__ISREL_DEF(greaterl, >, TASELDOUBLE)
__ISREL_DEF(greaterequalf, >=, float_t)
__ISREL_DEF(greaterequal, >=, double_t)
__ISREL_DEF(greaterequall, >=, TASELDOUBLE)

#define __tg_pred_2(x, y, p) ( \
	sizeof((x)+(y)) == sizeof(float) ? p##f(x, y) : \
	sizeof((x)+(y)) == sizeof(double) ? p(x, y) : \
	p##l(x, y) )

#define isless(x, y)            __tg_pred_2(x, y, __isless)
#define islessequal(x, y)       __tg_pred_2(x, y, __islessequal)
#define islessgreater(x, y)     __tg_pred_2(x, y, __islessgreater)
#define isgreater(x, y)         __tg_pred_2(x, y, __isgreater)
#define isgreaterequal(x, y)    __tg_pred_2(x, y, __isgreaterequal)

double      acos(double);
float       acosf(float);
TASELDOUBLE acosl(TASELDOUBLE);

double      acosh(double);
float       acoshf(float);
TASELDOUBLE acoshl(TASELDOUBLE);

double      asin(double);
float       asinf(float);
TASELDOUBLE asinl(TASELDOUBLE);

double      asinh(double);
float       asinhf(float);
TASELDOUBLE asinhl(TASELDOUBLE);

double      atan(double);
float       atanf(float);
TASELDOUBLE atanl(TASELDOUBLE);

double      atan2(double, double);
float       atan2f(float, float);
TASELDOUBLE atan2l(TASELDOUBLE, TASELDOUBLE);

double      atanh(double);
float       atanhf(float);
TASELDOUBLE atanhl(TASELDOUBLE);

double      cbrt(double);
float       cbrtf(float);
TASELDOUBLE cbrtl(TASELDOUBLE);

double      ceil(double);
float       ceilf(float);
TASELDOUBLE ceill(TASELDOUBLE);

double      copysign(double, double);
float       copysignf(float, float);
TASELDOUBLE copysignl(TASELDOUBLE, TASELDOUBLE);

double      cos(double);
float       cosf(float);
TASELDOUBLE cosl(TASELDOUBLE);

double      cosh(double);
float       coshf(float);
TASELDOUBLE coshl(TASELDOUBLE);

double      erf(double);
float       erff(float);
TASELDOUBLE erfl(TASELDOUBLE);

double      erfc(double);
float       erfcf(float);
TASELDOUBLE erfcl(TASELDOUBLE);

double      exp(double);
float       expf(float);
TASELDOUBLE expl(TASELDOUBLE);

double      exp2(double);
float       exp2f(float);
TASELDOUBLE exp2l(TASELDOUBLE);

double      expm1(double);
float       expm1f(float);
TASELDOUBLE expm1l(TASELDOUBLE);

double      fabs(double);
float       fabsf(float);
TASELDOUBLE fabsl(TASELDOUBLE);

double      fdim(double, double);
float       fdimf(float, float);
TASELDOUBLE fdiml(TASELDOUBLE, TASELDOUBLE);

double      floor(double);
float       floorf(float);
TASELDOUBLE floorl(TASELDOUBLE);

double      fma(double, double, double);
float       fmaf(float, float, float);
TASELDOUBLE fmal(TASELDOUBLE, TASELDOUBLE, TASELDOUBLE);

double      fmax(double, double);
float       fmaxf(float, float);
TASELDOUBLE fmaxl(TASELDOUBLE, TASELDOUBLE);

double      fmin(double, double);
float       fminf(float, float);
TASELDOUBLE fminl(TASELDOUBLE, TASELDOUBLE);

double      fmod(double, double);
float       fmodf(float, float);
TASELDOUBLE fmodl(TASELDOUBLE, TASELDOUBLE);

double      frexp(double, int *);
float       frexpf(float, int *);
TASELDOUBLE frexpl(TASELDOUBLE, int *);

double      hypot(double, double);
float       hypotf(float, float);
TASELDOUBLE hypotl(TASELDOUBLE, TASELDOUBLE);

int         ilogb(double);
int         ilogbf(float);
int         ilogbl(TASELDOUBLE);

double      ldexp(double, int);
float       ldexpf(float, int);
TASELDOUBLE ldexpl(TASELDOUBLE, int);

double      lgamma(double);
float       lgammaf(float);
TASELDOUBLE lgammal(TASELDOUBLE);

long long   llrint(double);
long long   llrintf(float);
long long   llrintl(TASELDOUBLE);

long long   llround(double);
long long   llroundf(float);
long long   llroundl(TASELDOUBLE);

double      log(double);
float       logf(float);
TASELDOUBLE logl(TASELDOUBLE);

double      log10(double);
float       log10f(float);
TASELDOUBLE log10l(TASELDOUBLE);

double      log1p(double);
float       log1pf(float);
TASELDOUBLE log1pl(TASELDOUBLE);

double      log2(double);
float       log2f(float);
TASELDOUBLE log2l(TASELDOUBLE);

double      logb(double);
float       logbf(float);
TASELDOUBLE logbl(TASELDOUBLE);

long        lrint(double);
long        lrintf(float);
long        lrintl(TASELDOUBLE);

long        lround(double);
long        lroundf(float);
long        lroundl(TASELDOUBLE);

double      modf(double, double *);
float       modff(float, float *);
TASELDOUBLE modfl(TASELDOUBLE, TASELDOUBLE *);

double      nan(const char *);
float       nanf(const char *);
TASELDOUBLE nanl(const char *);

double      nearbyint(double);
float       nearbyintf(float);
TASELDOUBLE nearbyintl(TASELDOUBLE);

double      nextafter(double, double);
float       nextafterf(float, float);
TASELDOUBLE nextafterl(TASELDOUBLE, TASELDOUBLE);

double      nexttoward(double, TASELDOUBLE);
float       nexttowardf(float, TASELDOUBLE);
TASELDOUBLE nexttowardl(TASELDOUBLE, TASELDOUBLE);

double      pow(double, double);
float       powf(float, float);
TASELDOUBLE powl(TASELDOUBLE, TASELDOUBLE);

double      remainder(double, double);
float       remainderf(float, float);
TASELDOUBLE remainderl(TASELDOUBLE, TASELDOUBLE);

double      remquo(double, double, int *);
float       remquof(float, float, int *);
TASELDOUBLE remquol(TASELDOUBLE, TASELDOUBLE, int *);

double      rint(double);
float       rintf(float);
TASELDOUBLE rintl(TASELDOUBLE);

double      round(double);
float       roundf(float);
TASELDOUBLE roundl(TASELDOUBLE);

double      scalbln(double, long);
float       scalblnf(float, long);
TASELDOUBLE scalblnl(TASELDOUBLE, long);

double      scalbn(double, int);
float       scalbnf(float, int);
TASELDOUBLE scalbnl(TASELDOUBLE, int);

double      sin(double);
float       sinf(float);
TASELDOUBLE sinl(TASELDOUBLE);

double      sinh(double);
float       sinhf(float);
TASELDOUBLE sinhl(TASELDOUBLE);

double      sqrt(double);
float       sqrtf(float);
TASELDOUBLE sqrtl(TASELDOUBLE);

double      tan(double);
float       tanf(float);
TASELDOUBLE tanl(TASELDOUBLE);

double      tanh(double);
float       tanhf(float);
TASELDOUBLE tanhl(TASELDOUBLE);

double      tgamma(double);
float       tgammaf(float);
TASELDOUBLE tgammal(TASELDOUBLE);

double      trunc(double);
float       truncf(float);
TASELDOUBLE truncl(TASELDOUBLE);


#if defined(_XOPEN_SOURCE) || defined(_BSD_SOURCE)
#undef  MAXFLOAT
#define MAXFLOAT        3.40282346638528859812e+38F
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define M_E             2.7182818284590452354   /* e */
#define M_LOG2E         1.4426950408889634074   /* log_2 e */
#define M_LOG10E        0.43429448190325182765  /* log_10 e */
#define M_LN2           0.69314718055994530942  /* log_e 2 */
#define M_LN10          2.30258509299404568402  /* log_e 10 */
#define M_PI            3.14159265358979323846  /* pi */
#define M_PI_2          1.57079632679489661923  /* pi/2 */
#define M_PI_4          0.78539816339744830962  /* pi/4 */
#define M_1_PI          0.31830988618379067154  /* 1/pi */
#define M_2_PI          0.63661977236758134308  /* 2/pi */
#define M_2_SQRTPI      1.12837916709551257390  /* 2/sqrt(pi) */
#define M_SQRT2         1.41421356237309504880  /* sqrt(2) */
#define M_SQRT1_2       0.70710678118654752440  /* 1/sqrt(2) */

extern int signgam;

double      j0(double);
double      j1(double);
double      jn(int, double);

double      y0(double);
double      y1(double);
double      yn(int, double);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define HUGE            3.40282346638528859812e+38F

double      drem(double, double);
float       dremf(float, float);

int         finite(double);
int         finitef(float);

double      scalb(double, double);
float       scalbf(float, float);

double      significand(double);
float       significandf(float);

double      lgamma_r(double, int*);
float       lgammaf_r(float, int*);

float       j0f(float);
float       j1f(float);
float       jnf(int, float);

float       y0f(float);
float       y1f(float);
float       ynf(int, float);
#endif

#ifdef _GNU_SOURCE
TASELDOUBLE lgammal_r(TASELDOUBLE, int*);

void        sincos(double, double*, double*);
void        sincosf(float, float*, float*);
void        sincosl(TASELDOUBLE, TASELDOUBLE*, TASELDOUBLE*);

double      exp10(double);
float       exp10f(float);
TASELDOUBLE exp10l(TASELDOUBLE);

double      pow10(double);
float       pow10f(float);
TASELDOUBLE pow10l(TASELDOUBLE);
#endif

#ifdef __cplusplus
}
#endif

#endif
