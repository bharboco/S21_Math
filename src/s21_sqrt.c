#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0) return S21_NAN;
  long double y = x;
  while (s21_fabsl((y * y - x)) > S21_EPS) {
    y = 0.5 * (y + x / y);
  }
  return y;
}