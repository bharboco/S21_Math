long double s21_floor(double x) {
  long double fract_part = x - (int)x, res = 0;
  if (fract_part == 0)
    res = x;
  else {
    if (x < 0)
      res = (x - 1) - fract_part;
    else
      res = x - fract_part;
  }
  return res;
}