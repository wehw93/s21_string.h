#include "test.h"

START_TEST(s21_strchr_test) {
  const char str_1[] = "123456789";
  int c_1 = '4';

  const char str_2[] = "AAAAAAAAAAbcd efg hijk";
  int c_2 = 'A';

  const char str_3[] = "\n";
  int c_3 = 'A';

  const char str_4[] = "\t";
  int c_4 = '4';

  const char str_5[] = "12345\n6789";
  int c_5 = '9';

  const char str_6[] = "\0123\0123\t1\0";
  int c_6 = '0';

  ck_assert_ptr_eq(s21_strchr(str_1, c_1), strchr(str_1, c_1));
  ck_assert_ptr_eq(s21_strchr(str_2, c_2), strchr(str_2, c_2));
  ck_assert_ptr_eq(s21_strchr(str_3, c_3), strchr(str_3, c_3));
  ck_assert_ptr_eq(s21_strchr(str_4, c_4), strchr(str_4, c_4));
  ck_assert_ptr_eq(s21_strchr(str_5, c_5), strchr(str_5, c_5));
  ck_assert_ptr_eq(s21_strchr(str_6, c_6), strchr(str_6, c_6));
  ck_assert_ptr_eq(s21_strchr(str_6, '\0'), strchr(str_6, '\0'));
  ck_assert_ptr_eq(s21_strchr(str_5, '\0'), strchr(str_5, '\0'));
}
END_TEST

Suite *suite_strchr() {
  Suite *st = suite_create("\033[45m-=s21_strchr_test=-\033[0m");
  TCase *tc_strchr = tcase_create("s21_strchr_test");
  tcase_add_test(tc_strchr, s21_strchr_test);

  suite_add_tcase(st, tc_strchr);
  return st;
}