#include "test.h"

START_TEST(s21_strncmp_test) {
  const char test_strncmp_1[] = "qwertyuiop";
  const char test_strncmp_01[] = "qwertyuiop";

  const char test_strncmp_2[] = "abbbbbbq";
  const char test_strncmp_02[] = "abbbbbbb";

  const char test_strncmp_3[] = "abbbbbbb";
  const char test_strncmp_03[] = "abbbbbbq";

  const char test_strncmp_4[] = "";
  const char test_strncmp_04[] = "qwertyuiop";

  const char test_strncmp_5[] = "qwertyuiop";
  const char test_strncmp_05[] = "";

  const char test_strncmp_6[] = "";
  const char test_strncmp_06[] = "";

  const char test_strncmp_7[] = "werttyuiopp";
  const char test_strncmp_07[] = "qwertyuiop";

  for (int n = 0; n < 20; n++) {
    ck_assert_int_eq(s21_strncmp(test_strncmp_1, test_strncmp_01, n),
                     strncmp(test_strncmp_1, test_strncmp_01, n));
    ck_assert_int_eq(s21_strncmp(test_strncmp_2, test_strncmp_02, n),
                     strncmp(test_strncmp_2, test_strncmp_02, n));
    ck_assert_int_eq(s21_strncmp(test_strncmp_3, test_strncmp_03, n),
                     strncmp(test_strncmp_3, test_strncmp_03, n));
    ck_assert_int_eq(s21_strncmp(test_strncmp_4, test_strncmp_04, n),
                     strncmp(test_strncmp_4, test_strncmp_04, n));
    ck_assert_int_eq(s21_strncmp(test_strncmp_5, test_strncmp_05, n),
                     strncmp(test_strncmp_5, test_strncmp_05, n));
    ck_assert_int_eq(s21_strncmp(test_strncmp_6, test_strncmp_06, n),
                     strncmp(test_strncmp_6, test_strncmp_06, n));
    ck_assert_int_eq(s21_strncmp(test_strncmp_7, test_strncmp_07, n),
                     strncmp(test_strncmp_7, test_strncmp_07, n));
  }
}
END_TEST

Suite *suite_strncmp() {
  Suite *st = suite_create("\033[45m-=s21_strncmp_test=-\033[0m");
  TCase *tc_strncmp = tcase_create("s21_strncmp_test");
  tcase_add_test(tc_strncmp, s21_strncmp_test);

  suite_add_tcase(st, tc_strncmp);
  return st;
}
