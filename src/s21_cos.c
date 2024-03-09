#include "s21_math.h"
// тригономирические функции
long double s21_cos(double x) { return s21_sin(S21_PI / 2 - x); }