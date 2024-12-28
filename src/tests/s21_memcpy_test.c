#include "test.h"

START_TEST(s21_memcpy_test) {
  char src1[] = "Hello, World!";
  char dest1[50] = {0};
  char dest2[50] = {0};
  char src2[] = "1234567890";
  char dest3[50] = {0};
  char dest4[50] = {0};
  char src3[] = "";
  char dest5[50] = {0};
  char dest6[50] = {0};
  char src4[100];
  for (size_t i = 0; i < sizeof(src4); i++) {
    src4[i] = (char)(i % 256);
  }
  char dest7[100] = {0};
  char dest8[100] = {0};
  ck_assert_mem_eq(s21_memcpy(dest1, src1, sizeof(src1)),
                   memcpy(dest2, src1, sizeof(src1)), sizeof(src1));

  ck_assert_mem_eq(s21_memcpy(dest3, src2, 5), memcpy(dest4, src2, 5), 5);

  ck_assert_mem_eq(s21_memcpy(dest5, src3, sizeof(src3)),
                   memcpy(dest6, src3, sizeof(src3)), sizeof(src3));

  ck_assert_mem_eq(s21_memcpy(dest7, src4, sizeof(src4)),
                   memcpy(dest8, src4, sizeof(src4)), sizeof(src4));
}
END_TEST

Suite *suite_memcpy() {
  Suite *st = suite_create("\033[45m-=s21_memcpy_test=-\033[0m");
  TCase *tc_memcpy = tcase_create("s21_memcpy_test");
  tcase_add_test(tc_memcpy, s21_memcpy_test);

  suite_add_tcase(st, tc_memcpy);
  return st;
}