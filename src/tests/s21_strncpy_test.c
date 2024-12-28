#include "test.h"

START_TEST(s21_strncpy_test) {
  char test_strncpy_1[] = "qwertyuiop";
  const char test_strncpy_01[] = "eeeee";

  char test_strncpy_2[] = "qwertyuiop";
  const char test_strncpy_02[] = "";

  char test_strncpy_3[] = "";
  const char test_strncpy_03[] = "qwertyuiop";

  for (int n = 0; n < 20; n++) {
    ck_assert_str_eq(s21_strncpy(test_strncpy_1, test_strncpy_01, n),
                     strncpy(test_strncpy_1, test_strncpy_01, n));
    ck_assert_str_eq(s21_strncpy(test_strncpy_2, test_strncpy_02, n),
                     strncpy(test_strncpy_2, test_strncpy_02, n));
    ck_assert_str_eq(s21_strncpy(test_strncpy_3, test_strncpy_03, n),
                     strncpy(test_strncpy_3, test_strncpy_03, n));
  }
}
END_TEST

Suite *suite_strncpy() {
  Suite *st = suite_create("\033[45m-=s21_strncpy_test=-\033[0m");
  TCase *tc_strncpy = tcase_create("s21_strncpy_test");
  tcase_add_test(tc_strncpy, s21_strncpy_test);

  suite_add_tcase(st, tc_strncpy);
  return st;
}
