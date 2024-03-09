#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(normal_s21_abs) {
  ck_assert_int_eq(s21_abs(-2), abs(-2));
  ck_assert_int_eq(s21_abs(-2456), abs(-2456));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(2), abs(2));
}
END_TEST

START_TEST(normal_s21_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(25.1, 2), pow(25.1, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -2), pow(-2, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2), pow(0, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, 0), pow(2, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 1.1), pow(0, 1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, S21_INFINITY), pow(0, INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, 1.2), pow(2, 1.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, -1.2), pow(2, -1.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, -1), pow(2, -1), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-9, 3.3));
}
END_TEST

START_TEST(normal_s21_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(2), exp(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-12), exp(-12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1.2), exp(1.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.98), exp(0.98), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(1050));
}
END_TEST

START_TEST(normal_s21_ceil) {
  ck_assert_ldouble_eq(s21_ceil(2.3), ceil(2.3));
  ck_assert_ldouble_eq(s21_ceil(-1.5), ceil(-1.5));
  ck_assert_ldouble_eq(s21_ceil(-2.4), ceil(-2.4));
  ck_assert_ldouble_eq(s21_ceil(1056.67), ceil(1056.67));
  ck_assert_ldouble_eq(s21_ceil(-5.99), ceil(-5.99));
  ck_assert_ldouble_eq(s21_ceil(5.199), ceil(5.199));
  ck_assert_ldouble_eq(s21_ceil(5), ceil(5));
  ck_assert_ldouble_eq(s21_ceil(5.0), ceil(5.0));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
}
END_TEST

START_TEST(normal_s21_floor) {
  ck_assert_ldouble_eq(s21_floor(2.3), floor(2.3));
  ck_assert_ldouble_eq(s21_floor(-1.5), floor(-1.5));
  ck_assert_ldouble_eq(s21_floor(-2.4), floor(-2.4));
  ck_assert_ldouble_eq(s21_floor(1056.67), floor(1056.67));
  ck_assert_ldouble_eq(s21_floor(-5.99), floor(-5.99));
  ck_assert_ldouble_eq(s21_floor(5.199), floor(5.199));
  ck_assert_ldouble_eq(s21_floor(5), floor(5));
  ck_assert_ldouble_eq(s21_floor(5.0), floor(5.0));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
}
END_TEST

START_TEST(normal_s21_fmod) {
  ck_assert_ldouble_eq_tol(s21_fmod(3, 2), fmod(3, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2, 2), fmod(2, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 2), fmod(0, 2), 1e-6);
  ck_assert_ldouble_nan(s21_fmod(3, 0));
  ck_assert_ldouble_eq_tol(s21_fmod(150, 56.67), fmod(150, 56.67), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.56, 2), fmod(0.56, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-0.56, -2), fmod(-0.56, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(53, -2), fmod(53, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.56, -2), fmod(0.56, -2), 1e-6);
}
END_TEST

START_TEST(normal_s21_log) {
  ck_assert_ldouble_eq_tol(s21_log(12), log(12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(5.567), log(5.567), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_nan(s21_log(-25));
  ck_assert_ldouble_eq_tol(s21_log(2.5), log(2.5), 1e-6);
  ck_assert_ldouble_nan(s21_log(-2.5));
}
END_TEST

START_TEST(normal_s21_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-10), sin(-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1050), sin(1050), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.708054), sin(0.708054), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(50), sin(50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(7), sin(7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(6), sin(6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(6.29), sin(6.29), 1e-6);
}
END_TEST

START_TEST(normal_s21_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-10), cos(-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1050), cos(1050), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.708054), cos(0.708054), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(50), cos(50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(7), cos(7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(6), cos(6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(6.29), cos(6.29), 1e-6);
}
END_TEST

START_TEST(normal_s21_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-10), tan(-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1050), tan(1050), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.708054), tan(0.708054), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(50), tan(50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(7), tan(7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(6), tan(6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(6.29), tan(6.29), 1e-6);
}
END_TEST

START_TEST(normal_s21_acos) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
  ck_assert_ldouble_nan(s21_acos(1050));
  ck_assert_ldouble_eq_tol(s21_acos(0.708054), acos(0.708054), 1e-6);
  ck_assert_ldouble_nan(s21_acos(7));
  ck_assert_ldouble_nan(s21_acos(6));
  ck_assert_ldouble_nan(s21_acos(6.29));
  ck_assert_ldouble_nan(s21_acos(-6.29));
}
END_TEST

START_TEST(normal_s21_asin) {
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.708054), asin(0.708054), 1e-6);
  ck_assert_ldouble_nan(s21_asin(10));
  ck_assert_ldouble_nan(s21_asin(-10));
  ck_assert_ldouble_nan(s21_asin(-1.5));
  ck_assert_ldouble_nan(s21_asin(1.5));
}
END_TEST

START_TEST(normal_s21_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.708054), atan(0.708054), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(10), atan(10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-10), atan(-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1.5), atan(-1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1.5), atan(1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INFINITY), atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INFINITY), atan(-INFINITY), 1e-6);
}
END_TEST

START_TEST(normal_s21_sqrt) {
  ck_assert_ldouble_nan(s21_sqrt(-1));
  ck_assert_ldouble_nan(s21_sqrt(-5.7));
  ck_assert_ldouble_eq_tol(s21_sqrt(23), sqrt(23), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2), sqrt(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(250), sqrt(250), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1050), sqrt(1050), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_math");
  TCase *tc1_1 = tcase_create("s21_math");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, normal_s21_abs);
  tcase_add_test(tc1_1, normal_s21_pow);
  tcase_add_test(tc1_1, normal_s21_exp);
  tcase_add_test(tc1_1, normal_s21_ceil);
  tcase_add_test(tc1_1, normal_s21_floor);
  tcase_add_test(tc1_1, normal_s21_fmod);
  tcase_add_test(tc1_1, normal_s21_log);
  tcase_add_test(tc1_1, normal_s21_sin);
  tcase_add_test(tc1_1, normal_s21_cos);
  tcase_add_test(tc1_1, normal_s21_tan);
  tcase_add_test(tc1_1, normal_s21_acos);
  tcase_add_test(tc1_1, normal_s21_asin);
  tcase_add_test(tc1_1, normal_s21_atan);
  tcase_add_test(tc1_1, normal_s21_sqrt);

  srunner_run_all(sr, CK_ENV);

  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
