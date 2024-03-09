#include "s21_math.h"

long double s21_exp(double x) {
  long double taylor_series = 1, result = 1, i = 1;
  while (s21_fabs(taylor_series) > S21_EPS) {
    taylor_series *= x / i;
    i++;
    result += taylor_series;
    if (result >= S21_DBLMAX) {
      result = S21_INFINITY;
      break;
    }
  }

  return result;
}