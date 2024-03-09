#include "s21_math.h"
// Нахождение синуса с помощью ряда Тейлора
long double s21_sin(double x) {
  x = s21_fmod(x, 2 * S21_PI);  // Приведение x к интервалу от 0 до 2π.
  long double accuracy = x, result = 0, i = 1;
  while (s21_fabsl(accuracy) > S21_EPS) {
    result = result + accuracy;
    accuracy = accuracy * (-1) * (x * x) / ((2 * i + 1) * (2 * i));
    i++;
  }
  return result;
}

long double s21_fabsl(long double x) {
  if (x < 0) x = x * -1;
  return x;
}