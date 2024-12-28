#include "test.h"

START_TEST(s21_memchr_test) {
  char test1[] = "HebaBuba";
  char test2 = 'M';
  char test3 = 'b';
  char test4[] = "8919/\0";
  char test5[] = "?";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  char test10[] = "";
  char test11[] = "1";
  char test12 = '1';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 9),
                    (unsigned long)memchr(test1, test2, 9));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 9),
                    (unsigned long)memchr(test1, test3, 9));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 7),
                    (unsigned long)memchr(test4, test6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 7),
                    (unsigned long)memchr(test4, test8, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 7),
                    (unsigned long)memchr(test4, test9, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test10, test7, 1),
                    (unsigned long)memchr(test10, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test11, test12, 1),
                    (unsigned long)memchr(test11, test12, 1));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *st = suite_create("\033[45m-=s21_memchr_test=-\033[0m");
  TCase *tc_memchr = tcase_create("s21_memchr_test");
  tcase_add_test(tc_memchr, s21_memchr_test);

  suite_add_tcase(st, tc_memchr);
  return st;
}