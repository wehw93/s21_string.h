#include "test.h"

START_TEST(s21_strerror_test) {
  for (int i = -1000; i < 1000; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_strerror() {
  Suite *st = suite_create("\033[45m-=s21_strerror_test=-\033[0m");
  TCase *tc_strerror = tcase_create("s21_strerror_test");
  tcase_add_test(tc_strerror, s21_strerror_test);

  suite_add_tcase(st, tc_strerror);
  return st;
}
