#ifndef MATH_H_
#define MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define S21_E 2.718281828459045
#define S21_EPS 1e-9
#define S21_INFINITY 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_PI 3.14159265358979323846264338327950288
#define S21_DBLMAX 1.7976931348623157E+308

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_fabsl(long double x);

#endif  // MATH_H_