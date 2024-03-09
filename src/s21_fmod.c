#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (y < 0 && x > 0) y = y * -1;
  long double z = x / y;
  z = s21_floor(z);  // округляем в меньшую сторону
  z = x - z * y;
  return z;
}