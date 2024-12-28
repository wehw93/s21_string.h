#include "test.h"

START_TEST(s21_strstr_test) {
  const char test_strstr_1[] = "Hello World";
  ck_assert_str_eq(s21_strstr(test_strstr_1, "lo"),
                   strstr(test_strstr_1, "lo"));
  ck_assert_str_eq(s21_strstr(test_strstr_1, "World"),
                   strstr(test_strstr_1, "World"));
  ck_assert_ptr_eq(s21_strstr(test_strstr_1, "XYZ"),
                   strstr(test_strstr_1, "XYZ"));

  const char test_strstr_2[] = "aaaaaaa";
  ck_assert_str_eq(s21_strstr(test_strstr_2, "aaa"),
                   strstr(test_strstr_2, "aaa"));
  ck_assert_ptr_eq(s21_strstr(test_strstr_2, "b"), strstr(test_strstr_2, "b"));

  const char test_strstr_3[] = "abc\0def";
  ck_assert_str_eq(s21_strstr(test_strstr_3, "abc"),
                   strstr(test_strstr_3, "abc"));
  ck_assert_ptr_eq(s21_strstr(test_strstr_3, "def"),
                   strstr(test_strstr_3, "def"));
  ck_assert_ptr_eq(s21_strstr(test_strstr_3, "\0"),
                   strstr(test_strstr_3, "\0"));

  const char test_strstr_4[] = "";
  ck_assert_ptr_eq(s21_strstr(test_strstr_4, ""), strstr(test_strstr_4, ""));
  ck_assert_ptr_eq(s21_strstr(test_strstr_4, "test"),
                   strstr(test_strstr_4, "test"));

  const char test_strstr_5[] = "Sample text";
  ck_assert_str_eq(s21_strstr(test_strstr_5, ""), strstr(test_strstr_5, ""));

  const char test_strstr_6[] = "short";
  ck_assert_ptr_eq(s21_strstr(test_strstr_6, "verylongsubstring"),
                   strstr(test_strstr_6, "verylongsubstring"));

  const char test_strstr_7[] = "a";
  ck_assert_str_eq(s21_strstr(test_strstr_7, "a"), strstr(test_strstr_7, "a"));
  ck_assert_ptr_eq(s21_strstr(test_strstr_7, "b"), strstr(test_strstr_7, "b"));
  ck_assert_ptr_eq(s21_strstr(test_strstr_7, ""), strstr(test_strstr_7, ""));

  const char test_strstr_8[] = "   ";
  ck_assert_str_eq(s21_strstr(test_strstr_8, " "), strstr(test_strstr_8, " "));
  ck_assert_ptr_eq(s21_strstr(test_strstr_8, "test"),
                   strstr(test_strstr_8, "test"));
}
END_TEST

Suite *suite_strstr() {
  Suite *st = suite_create("\033[45m-=s21_strstr_test=-\033[0m");
  TCase *tc_strstr = tcase_create("s21_strstr_test");
  tcase_add_test(tc_strstr, s21_strstr_test);
  suite_add_tcase(st, tc_strstr);
  return st;
}
