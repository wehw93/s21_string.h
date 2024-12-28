#include "test.h"

START_TEST(s21_insert_test) {
  const char test_insert_1[] = "qwert";
  const char test_insert_01[] = "12";

  const char test_insert_2[] = "qwert";
  const char test_insert_02[] = "";

  const char test_insert_3[] = "";
  const char test_insert_03[] = "qwert";

  const char *test_insert_4 = s21_NULL;
  const char test_insert_04[] = "qwertyuiop";

  const char test_insert_5[] = "qwertyuiop";
  const char *test_insert_05 = s21_NULL;

  const char *test_insert_6 = s21_NULL;
  const char *test_insert_06 = s21_NULL;

  char *result = (char *)s21_insert(test_insert_1, test_insert_01, 0);
  ck_assert_str_eq(result, "12qwert");
  free(result);

  result = (char *)s21_insert(test_insert_1, test_insert_01, 2);
  ck_assert_str_eq(result, "qw12ert");
  free(result);

  result = (char *)s21_insert(test_insert_1, test_insert_01, 5);
  ck_assert_str_eq(result, "qwert12");
  free(result);

  result = (char *)s21_insert(test_insert_2, test_insert_02, 0);
  ck_assert_str_eq(result, "qwert");
  free(result);

  result = (char *)s21_insert(test_insert_2, test_insert_02, 2);
  ck_assert_str_eq(result, "qwert");
  free(result);

  result = (char *)s21_insert(test_insert_2, test_insert_02, 5);
  ck_assert_str_eq(result, "qwert");
  free(result);

  result = (char *)s21_insert(test_insert_3, test_insert_03, 0);
  ck_assert_str_eq(result, "qwert");
  free(result);

  result = s21_insert(test_insert_3, test_insert_03, 5);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);

  result = s21_insert(test_insert_4, test_insert_04, 0);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);

  result = s21_insert(test_insert_5, test_insert_05, 0);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);

  result = s21_insert(test_insert_6, test_insert_06, 0);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);
}
END_TEST

Suite *suite_insert() {
  Suite *st = suite_create("\033[45m-=s21_insert_test=-\033[0m");
  TCase *tc_insert = tcase_create("s21_insert_test");
  tcase_add_test(tc_insert, s21_insert_test);

  suite_add_tcase(st, tc_insert);
  return st;
}