#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    result =
        (char *)calloc((s21_strlen(src) + s21_strlen(str) + 1), sizeof(char));
  }
  if (result != s21_NULL && start_index <= s21_strlen(src)) {
    char *p = result;
    for (int i = 0; i < (int)start_index; i++) {
      *(p++) = *(src++);
    }
    while (*str != '\0') {
      *(p++) = *(str++);
    }

    while (*src != '\0') {
      *(p++) = *(src++);
    }
    *p = '\0';
  } else {
    free(result);
    result = s21_NULL;
  }
  return (void *)result;
}
