#include "test.h"

START_TEST(s21_memcmp_test) {
  char src1[] = {1, 2, 3};
  char src2[] = {1, 2, 3};

  char src3[] = {1, 2, 3};
  char src4[] = {0, 2, 3};

  char src5[] = {1, 2, 3};
  char src6[] = {1, 0, 3};

  char src7[] = {1, 2, 3};
  char src8[] = {1, 2, 4};

  char src9[] = {1, 2, 3};
  char src10[] = {4, 5, 6};

  char src11[] = {1};
  char src12[] = {1};

  char src13[] = {2};

  char src14[] = {1, 2, 3};
  char src15[] = {1, 2, 4};

  char src16[] = {1, '\0', 3};
  char src17[] = {1, '\0', 4};

  char src18[] = {-1, 2, 3};
  char src19[] = {127, 2, 3};

  char src20[1000] = {0};
  char src21[1000] = {0};
  src21[999] = 1;

  char src22[] = "Hello School21!\n";
  char src23[] = "Hello, School21!\n";

  ck_assert_int_eq(s21_memcmp(src1, src2, 3), memcmp(src1, src2, 3));
  ck_assert_int_eq(s21_memcmp(src3, src4, 3), memcmp(src3, src4, 3));
  ck_assert_int_eq(s21_memcmp(src5, src6, 3), memcmp(src5, src6, 3));
  ck_assert_int_eq(s21_memcmp(src7, src8, 3), memcmp(src7, src8, 3));
  ck_assert_int_eq(s21_memcmp(src9, src10, 0), memcmp(src9, src10, 0));
  ck_assert_int_eq(s21_memcmp(src11, src12, 1), memcmp(src11, src12, 1));
  ck_assert_int_eq(s21_memcmp(src13, src13, 2), memcmp(src13, src13, 2));
  ck_assert_int_eq(s21_memcmp(src14, src15, 3), memcmp(src14, src15, 3));
  ck_assert_int_eq(s21_memcmp(src16, src17, 1), memcmp(src16, src17, 1));
  ck_assert_int_eq(s21_memcmp(src18, src19, 1), memcmp(src18, src19, 1));
  ck_assert_int_eq(s21_memcmp(src20, src21, 1000), memcmp(src20, src21, 1000));
  ck_assert_int_eq(s21_memcmp(src22, src23, sizeof(src22)),
                   memcmp(src22, src23, sizeof(src22)));
}
END_TEST

Suite *suite_memcmp() {
  Suite *st = suite_create("\033[45m-=s21_memcmp_test=-\033[0m");
  TCase *tc_memcpy = tcase_create("s21_memcpy_test");
  tcase_add_test(tc_memcpy, s21_memcmp_test);

  suite_add_tcase(st, tc_memcpy);
  return st;
}