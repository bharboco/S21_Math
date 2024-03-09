#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (exp == (long int)exp) {
    if (exp < 0) {
      base = 1 / base;
      exp *= -1;
    }
    for (int i = 1; i <= exp; i++) result *= base;
  } else {
    if (base == 0) {
      result = 0;
      if (exp < 0) result = S21_INFINITY;
    } else if (base < 0) {
      result = S21_NAN;
    } else {
      result = s21_exp(exp * s21_log(base));  // e ^ exp * ln base
    }
  }
  return result;
}