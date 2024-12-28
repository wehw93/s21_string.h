#include "test.h"

START_TEST(s21_trim_test) {
  const char *src = "  hello  ";
  const char *expected = "hello";
  char *result = s21_trim(src, s21_NULL);
  ck_assert_str_eq(result, expected);
  free(result);

  const char *src2 = "--hello--";
  const char *expected2 = "hello";
  char *result2 = s21_trim(src2, "-");
  ck_assert_str_eq(result2, expected2);
  free(result2);

  const char *src3 = "hello";
  const char *expected3 = "hello";
  char *result3 = s21_trim(src3, s21_NULL);
  ck_assert_str_eq(result3, expected3);
  free(result3);

  const char *src4 = "";
  const char *expected4 = "";
  char *result4 = s21_trim(src4, s21_NULL);
  ck_assert_str_eq(result4, expected4);
  free(result4);

  const char *src5 = "    ";
  const char *expected5 = "";
  char *result5 = s21_trim(src5, s21_NULL);
  ck_assert_str_eq(result5, expected5);
  free(result5);

  const char *src6 = "\t\n\v\r\f hello \t\n";
  const char *expected6 = "hello";
  char *result6 = s21_trim(src6, s21_NULL);
  ck_assert_str_eq(result6, expected6);
  free(result6);

  const char *src7 = "@@@hello@@@";
  const char *expected7 = "hello";
  char *result7 = s21_trim(src7, "@");
  ck_assert_str_eq(result7, expected7);
  free(result7);
}
END_TEST

Suite *suite_trim() {
  Suite *st = suite_create("\033[45m-=s21_trim_test=-\033[0m");
  TCase *tc_trim = tcase_create("s21_trim_test");
  tcase_add_test(tc_trim, s21_trim_test);

  suite_add_tcase(st, tc_trim);
  return st;
}