#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <taseldouble.h>

#ifdef __cplusplus
extern "C" {
#endif

#define complex _Complex
#ifdef __GNUC__
#define _Complex_I (__extension__ (0.0f+1.0fi))
#else
#define _Complex_I (0.0f+1.0fi)
#endif
#define I _Complex_I

double complex cacos(double complex);
float complex cacosf(float complex);
TASELDOUBLE complex cacosl(TASELDOUBLE complex);

double complex casin(double complex);
float complex casinf(float complex);
TASELDOUBLE complex casinl(TASELDOUBLE complex);

double complex catan(double complex);
float complex catanf(float complex);
TASELDOUBLE complex catanl(TASELDOUBLE complex);

double complex ccos(double complex);
float complex ccosf(float complex);
TASELDOUBLE complex ccosl(TASELDOUBLE complex);

double complex csin(double complex);
float complex csinf(float complex);
TASELDOUBLE complex csinl(TASELDOUBLE complex);

double complex ctan(double complex);
float complex ctanf(float complex);
TASELDOUBLE complex ctanl(TASELDOUBLE complex);

double complex cacosh(double complex);
float complex cacoshf(float complex);
TASELDOUBLE complex cacoshl(TASELDOUBLE complex);

double complex casinh(double complex);
float complex casinhf(float complex);
TASELDOUBLE complex casinhl(TASELDOUBLE complex);

double complex catanh(double complex);
float complex catanhf(float complex);
TASELDOUBLE complex catanhl(TASELDOUBLE complex);

double complex ccosh(double complex);
float complex ccoshf(float complex);
TASELDOUBLE complex ccoshl(TASELDOUBLE complex);

double complex csinh(double complex);
float complex csinhf(float complex);
TASELDOUBLE complex csinhl(TASELDOUBLE complex);

double complex ctanh(double complex);
float complex ctanhf(float complex);
TASELDOUBLE complex ctanhl(TASELDOUBLE complex);

double complex cexp(double complex);
float complex cexpf(float complex);
TASELDOUBLE complex cexpl(TASELDOUBLE complex);

double complex clog(double complex);
float complex clogf(float complex);
TASELDOUBLE complex clogl(TASELDOUBLE complex);

double cabs(double complex);
float cabsf(float complex);
TASELDOUBLE cabsl(TASELDOUBLE complex);

double complex cpow(double complex, double complex);
float complex cpowf(float complex, float complex);
TASELDOUBLE complex cpowl(TASELDOUBLE complex, TASELDOUBLE complex);

double complex csqrt(double complex);
float complex csqrtf(float complex);
TASELDOUBLE complex csqrtl(TASELDOUBLE complex);

double carg(double complex);
float cargf(float complex);
TASELDOUBLE cargl(TASELDOUBLE complex);

double cimag(double complex);
float cimagf(float complex);
TASELDOUBLE cimagl(TASELDOUBLE complex);

double complex conj(double complex);
float complex conjf(float complex);
TASELDOUBLE complex conjl(TASELDOUBLE complex);

double complex cproj(double complex);
float complex cprojf(float complex);
TASELDOUBLE complex cprojl(TASELDOUBLE complex);

double creal(double complex);
float crealf(float complex);
TASELDOUBLE creall(TASELDOUBLE complex);

#ifndef __cplusplus
#define __CIMAG(x, t) \
	(+(union { _Complex t __z; t __xy[2]; }){(_Complex t)(x)}.__xy[1])

#define creal(x) ((double)(x))
#define crealf(x) ((float)(x))
#define creall(x) ((TASELDOUBLE)(x))

#define cimag(x) __CIMAG(x, double)
#define cimagf(x) __CIMAG(x, float)
#define cimagl(x) __CIMAG(x, TASELDOUBLE)
#endif

#if __STDC_VERSION__ >= 201112L
#if defined(_Imaginary_I)
#define __CMPLX(x, y, t) ((t)(x) + _Imaginary_I*(t)(y))
#elif defined(__clang__)
#define __CMPLX(x, y, t) (+(_Complex t){ (t)(x), (t)(y) })
#else
#define __CMPLX(x, y, t) (__builtin_complex((t)(x), (t)(y)))
#endif
#define CMPLX(x, y) __CMPLX(x, y, double)
#define CMPLXF(x, y) __CMPLX(x, y, float)
#define CMPLXL(x, y) __CMPLX(x, y, TASELDOUBLE)
#endif

#ifdef __cplusplus
}
#endif
#endif
