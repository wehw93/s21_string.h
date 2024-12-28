#include "test.h"

START_TEST(s21_strpbrk_test) {
  const char test_strpbrk_1[] = "Hello, Worold";
  const char test_strpbrk_2[] = "WORLD HEllo";
  const char test_strpbrk_3[] = "ooooo";
  const char test_strpbrk_5[] = "12344325322312";
  const char test_strpbrk_6[] = "1\t1\0433fdsfsdjhello";
  ck_assert_str_eq(s21_strpbrk(test_strpbrk_1, "W"),
                   strpbrk(test_strpbrk_1, "W"));
  ck_assert_str_eq(s21_strpbrk(test_strpbrk_2, "H"),
                   strpbrk(test_strpbrk_2, "H"));
  ck_assert_str_eq(s21_strpbrk(test_strpbrk_3, "o"),
                   strpbrk(test_strpbrk_3, "o"));
  ck_assert_str_eq(s21_strpbrk(test_strpbrk_5, "5"),
                   strpbrk(test_strpbrk_5, "5"));
  ck_assert_str_eq(s21_strpbrk(test_strpbrk_6, "h"),
                   strpbrk(test_strpbrk_6, "h"));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *st = suite_create("\033[45m-=s21_strpbrk_test=-\033[0m");
  TCase *tc_strpbrk = tcase_create("s21_strpbrk_test");
  tcase_add_test(tc_strpbrk, s21_strpbrk_test);

  suite_add_tcase(st, tc_strpbrk);
  return st;
}
