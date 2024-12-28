#include "test.h"

int main() {
  int failed = 0;
  Suite *s21_string_test[] = {
      suite_strncmp(), suite_memset(),  suite_strrchr(),  suite_strncpy(),
      suite_strncat(), suite_strstr(),  suite_strtok(),   suite_memcpy(),
      suite_memchr(),  suite_memcmp(),  suite_sprintf(),  suite_strlen(),
      suite_strchr(),  suite_strcspn(), suite_strpbrk(),  suite_strerror(),
      suite_insert(),  suite_trim(),    suite_to_upper(), suite_to_lower(),
      s21_NULL};

  for (int i = 0; s21_string_test[i] != s21_NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
