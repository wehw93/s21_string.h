
#include "test.h"

START_TEST(s21_strlen_test) {
  const char test_strlen_1[] = "123456789";
  const char test_strlen_2[] = "12345678A";
  const char test_strlen_3[] = "9876543210";
  const char test_strlen_4[] = "9876543210";
  const char test_strlen_5[] = "12345\n6789";
  const char test_strlen_6[] = "1\t1\0";
  const char test_strlen_7[] = "\0";
  ck_assert_int_eq(s21_strlen(test_strlen_1), strlen(test_strlen_1));
  ck_assert_int_eq(s21_strlen(test_strlen_2), strlen(test_strlen_2));
  ck_assert_int_eq(s21_strlen(test_strlen_3), strlen(test_strlen_3));
  ck_assert_int_eq(s21_strlen(test_strlen_4), strlen(test_strlen_4));
  ck_assert_int_eq(s21_strlen(test_strlen_5), strlen(test_strlen_5));
  ck_assert_int_eq(s21_strlen(test_strlen_6), strlen(test_strlen_6));
  ck_assert_int_eq(s21_strlen(test_strlen_7), strlen(test_strlen_7));
}
END_TEST

Suite *suite_strlen() {
  Suite *st = suite_create("\033[45m-=s21_strlen_test=-\033[0m");
  TCase *tc_strlen = tcase_create("s21_strlen_test");
  tcase_add_test(tc_strlen, s21_strlen_test);

  suite_add_tcase(st, tc_strlen);
  return st;
}