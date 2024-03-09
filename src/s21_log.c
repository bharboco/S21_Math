#include "s21_math.h"

long double s21_log(double x) {
  if (x == S21_INFINITY) return x;
  if (x == 0) return -S21_INFINITY;
  if (x < 0) return S21_NAN;
  int count_e = 0;
  double result = 0;
  while (x >= S21_E) {
    x /= S21_E;
    count_e++;  // сколько раз экспонента поместилась в число х
  }
  for (int i = 0; i < 100; i++) {
    result = result + 2 * (x - s21_exp(result)) / (x + s21_exp(result));
  }
  return (result + count_e);
}