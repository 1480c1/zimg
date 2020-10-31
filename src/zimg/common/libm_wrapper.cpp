#include "libm_wrapper.h"
#define __CRT__NO_INLINE 1
#include <math.h>

float (*zimg_x_expf)(float) = expf;
float (*zimg_x_logf)(float) = logf;
float (*zimg_x_log10f)(float) = log10f;

float (*zimg_x_powf)(float, float) = powf;

double (*zimg_x_sin)(double) = sin;
double (*zimg_x_cos)(double) = cos;
