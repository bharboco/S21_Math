#include "s21_math.h"
long double s21_fabs(
    double x) {  // если число больше либо равно 0 возвращает x, если x<0
  // то переварачивает x на положительное
  if (x < 0) x = x * -1;
  return x;
}