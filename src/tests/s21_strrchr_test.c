#include "test.h"

START_TEST(s21_strrchr_test) {
  const char empty_string[] = "";
  ck_assert_ptr_eq(s21_strrchr(empty_string, 'a'), strrchr(empty_string, 'a'));

  const char no_match[] = "abcdef";
  ck_assert_ptr_eq(s21_strrchr(no_match, 'z'), strrchr(no_match, 'z'));

  const char single_occurrence[] = "abcdefg";
  ck_assert_ptr_eq(s21_strrchr(single_occurrence, 'd'),
                   strrchr(single_occurrence, 'd'));

  ck_assert_ptr_eq(s21_strrchr(s21_NULL, 'a'), s21_NULL);

  const char with_null[] = "hello\0world";
  ck_assert_ptr_eq(s21_strrchr(with_null, '\0'), strrchr(with_null, '\0'));

  const char long_string[1024] = {[0 ... 1022] = 'a', [1023] = '\0'};
  ck_assert_ptr_eq(s21_strrchr(long_string, 'a'), strrchr(long_string, 'a'));

  const char repeated_chars[] = "aaaaaa";
  ck_assert_ptr_eq(s21_strrchr(repeated_chars, 'a'),
                   strrchr(repeated_chars, 'a'));

  const char ends_with_char[] = "hello world!";
  ck_assert_ptr_eq(s21_strrchr(ends_with_char, '!'),
                   strrchr(ends_with_char, '!'));

  const char with_spaces[] = "   a   b   c   ";
  ck_assert_ptr_eq(s21_strrchr(with_spaces, 'b'), strrchr(with_spaces, 'b'));

  const char control_chars[] = "abc\tdef\nghi";
  ck_assert_ptr_eq(s21_strrchr(control_chars, '\t'),
                   strrchr(control_chars, '\t'));
  ck_assert_ptr_eq(s21_strrchr(control_chars, '\n'),
                   strrchr(control_chars, '\n'));
}
END_TEST

Suite *suite_strrchr() {
  Suite *st = suite_create("\033[45m-=s21_strrchr_test=-\033[0m");
  TCase *tc_strrchr = tcase_create("s21_strrchr_test");
  tcase_add_test(tc_strrchr, s21_strrchr_test);
  suite_add_tcase(st, tc_strrchr);
  return st;
}
