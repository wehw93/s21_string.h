#include "test.h"

START_TEST(s21_to_lower_test) {
  const char test_lower_1[] = "abcdefgHIJKLMNOP";
  const char test_lower_2[] = "abcd123456789efg";
  const char test_lower_3[] = "12345\n6789";
  char *result;
  result = s21_to_lower(test_lower_1);
  ck_assert_str_eq(result, "abcdefghijklmnop");
  if (result) free(result);
  result = s21_to_lower(test_lower_2);
  ck_assert_str_eq(result, "abcd123456789efg");
  if (result) free(result);
  result = s21_to_lower(test_lower_3);
  ck_assert_str_eq(result, "12345\n6789");
  if (result) free(result);
}
END_TEST

Suite *suite_to_lower() {
  Suite *st = suite_create("\033[45m-=s21_to_lower_test=-\033[0m");
  TCase *tc_to_lower = tcase_create("s21_to_lower_test");
  tcase_add_test(tc_to_lower, s21_to_lower_test);

  suite_add_tcase(st, tc_to_lower);
  return st;
}