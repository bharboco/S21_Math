#include "s21_math.h"

long double s21_atan(double x) {
  int invalid = (x > -1 && x < 1);  // bool
  long double res = 0;
  if (x == S21_INFINITY) {
    res = S21_PI / 2.0;
  } else if (x == -S21_INFINITY) {
    res = -S21_PI / 2.0;
  } else if (x == 1) {
    res = S21_PI / 4.0;
  } else if (x == -1) {
    res = -S21_PI / 4.0;
  } else {
    res = invalid ? x : 1.0 / x;
    for (int i = 1; i < 5000;
         i++) {  // через ряд тейлора с минимального элемента 1
      double chislitel =
          s21_pow(-1, i) * s21_pow(x, (1 + (2 * i)) * (invalid ? 1 : -1));
      double znamenatel = 1 + (2 * i);
      res += chislitel / znamenatel;
    }
    if (!invalid) res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
  }
  return res;
}