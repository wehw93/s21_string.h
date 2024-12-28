#include "test.h"

START_TEST(s21_memset_test) {
  const int c_array[] = {'f', '1', '\n', ' ', '\t', 27};

  char test_memset_1[] = "qwertyuiop";
  char test_memset_01[] = "qwertyuiop";
  char test_memset_2[] = " ";
  char test_memset_02[] = " ";

  for (int n = 0; n < 10; n++) {
    for (int c_array_index = 0; c_array_index < 6; c_array_index++) {
      ck_assert_str_eq(s21_memset(test_memset_1, c_array[c_array_index], n),
                       memset(test_memset_01, c_array[c_array_index], n));
    }
  }
  for (int c_array_index = 0; c_array_index < 6; c_array_index++) {
    ck_assert_str_eq(s21_memset(test_memset_2, c_array[c_array_index], 1),
                     memset(test_memset_02, c_array[c_array_index], 1));
  }
}
END_TEST

Suite *suite_memset() {
  Suite *st = suite_create("\033[45m-=s21_memset_test=-\033[0m");
  TCase *tc_memset = tcase_create("s21_memset_test");
  tcase_add_test(tc_memset, s21_memset_test);

  suite_add_tcase(st, tc_memset);
  return st;
}
