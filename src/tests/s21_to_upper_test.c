
#include "test.h"

START_TEST(s21_to_upper_test) {
  const char test_upper_1[] = "abcdefgHIJKLMNOP";
  const char test_upper_2[] = "abcd123456789efg";
  const char test_upper_3[] = "12345\n6789";
  char *result;
  result = s21_to_upper(test_upper_1);
  ck_assert_str_eq(result, "ABCDEFGHIJKLMNOP");
  if (result) free(result);
  result = s21_to_upper(test_upper_2);
  ck_assert_str_eq(result, "ABCD123456789EFG");
  if (result) free(result);
  result = s21_to_upper(test_upper_3);
  ck_assert_str_eq(result, "12345\n6789");
  if (result) free(result);
}
END_TEST

Suite *suite_to_upper() {
  Suite *st = suite_create("\033[45m-=s21_to_upper_test=-\033[0m");
  TCase *tc_to_upper = tcase_create("s21_to_upper_test");
  tcase_add_test(tc_to_upper, s21_to_upper_test);

  suite_add_tcase(st, tc_to_upper);
  return st;
}