
#include "test.h"

START_TEST(s21_strncat_test) {
  char str_1[] = "123456789";
  char str_2[] = "Abcd efg hijk";
  char str_3[] = "\n";
  char str_4[] = "\t";
  char str_5[] = "1234\n56789";
  char str_6[] = "1\t1\0";
  ck_assert_str_eq((s21_strncat(str_1, str_2, 1)), (strncat(str_1, str_2, 1)));
  ck_assert_str_eq(s21_strncat(str_2, "", 2), strncat(str_2, "", 2));
  ck_assert_str_eq(s21_strncat(str_3, "\t123", 1), strncat(str_3, "\t123", 1));
  ck_assert_str_eq(s21_strncat(str_4, "\n123", 1), strncat(str_4, "\n123", 1));
  ck_assert_str_eq(s21_strncat(str_5, " ", 5), strncat(str_5, " ", 5));
  ck_assert_str_eq(s21_strncat(str_6, "QWE123", 3),
                   strncat(str_6, "QWE123", 3));
}
END_TEST

Suite *suite_strncat() {
  Suite *st = suite_create("\033[45m-=s21_strncat_test=-\033[0m");
  TCase *tc_strncat = tcase_create("s21_strncat_test");
  tcase_add_test(tc_strncat, s21_strncat_test);

  suite_add_tcase(st, tc_strncat);
  return st;
}