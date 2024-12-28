#include "test.h"

START_TEST(s21_strcspn_test) {
  const char test_strcspn_1[] = "Hello, Worold";
  const char test_strcspn_2[] = "WORLD HEllo";
  const char test_strcspn_3[] = "ooooo";
  const char test_strcspn_5[] = "12344325322312";
  const char test_strcspn_6[] = "1\t1\0433fdsfsdjhello";
  ck_assert_int_eq(s21_strcspn(test_strcspn_1, "W"),
                   strcspn(test_strcspn_1, "W"));
  ck_assert_int_eq(s21_strcspn(test_strcspn_2, "H"),
                   strcspn(test_strcspn_2, "H"));
  ck_assert_int_eq(s21_strcspn(test_strcspn_3, "o"),
                   strcspn(test_strcspn_3, "o"));
  ck_assert_int_eq(s21_strcspn(test_strcspn_5, "5"),
                   strcspn(test_strcspn_5, "5"));
  ck_assert_int_eq(s21_strcspn(test_strcspn_6, "h"),
                   strcspn(test_strcspn_6, "h"));
}
END_TEST

Suite *suite_strcspn() {
  Suite *st = suite_create("\033[45m-=s21_strcspn_test=-\033[0m");
  TCase *tc_strcspn = tcase_create("s21_strcspn_test");
  tcase_add_test(tc_strcspn, s21_strcspn_test);

  suite_add_tcase(st, tc_strcspn);
  return st;
}
