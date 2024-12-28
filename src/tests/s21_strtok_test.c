#include "test.h"
START_TEST(s21_strtok_test) {
  ck_assert_ptr_eq(s21_strtok((char *)s21_NULL, ","), s21_NULL);
  const char empty_string[] = "";
  ck_assert_ptr_eq(s21_strtok((char *)empty_string, ","),
                   strtok((char *)empty_string, ","));

  const char no_delimiters[] = "abcdef";
  ck_assert_str_eq(s21_strtok((char *)no_delimiters, ","),
                   strtok((char *)no_delimiters, ","));
  ck_assert_ptr_eq(s21_strtok(s21_NULL, ","), strtok(s21_NULL, ","));

  char single_delimiter[] = "a,b,c";
  char *s21_token = s21_strtok(single_delimiter, ",");
  char *std_token = strtok(single_delimiter, ",");
  while (s21_token && std_token) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(s21_NULL, ",");
    std_token = strtok(s21_NULL, ",");
  }

  char multiple_delimiters[] = ",,a,,b,c,,";
  s21_token = s21_strtok(multiple_delimiters, ",");
  std_token = strtok(multiple_delimiters, ",");
  while (s21_token && std_token) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(s21_NULL, ",");
    std_token = strtok(s21_NULL, ",");
  }

  char only_delimiters[] = ",,,,";
  ck_assert_ptr_eq(s21_strtok(only_delimiters, ","),
                   strtok(only_delimiters, ","));

  char spaces_and_delimiters[] = " a , b , c ";
  s21_token = s21_strtok(spaces_and_delimiters, ", ");
  std_token = strtok(spaces_and_delimiters, ", ");
  while (s21_token && std_token) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(s21_NULL, ", ");
    std_token = strtok(s21_NULL, ", ");
  }

  char input[] = "token1,token2,token3";
  s21_token = s21_strtok(input, ",");
  std_token = strtok(input, ",");
  while (s21_token && std_token) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(s21_NULL, ",");
    std_token = strtok(s21_NULL, ",");
  }

  char null_delimiter[] = "abc\0def";
  ck_assert_ptr_eq(s21_strtok(null_delimiter, "\0"),
                   strtok(null_delimiter, "\0"));

  char control_chars[] = "abc\tdef\nghi";
  s21_token = s21_strtok(control_chars, "\t\n");
  std_token = strtok(control_chars, "\t\n");
  while (s21_token && std_token) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(s21_NULL, "\t\n");
    std_token = strtok(s21_NULL, "\t\n");
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *st = suite_create("\033[45m-=s21_strtok_test=-\033[0m");
  TCase *tc_strtok = tcase_create("s21_strtok_test");
  tcase_add_test(tc_strtok, s21_strtok_test);
  suite_add_tcase(st, tc_strtok);
  return st;
}
