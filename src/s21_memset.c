#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *str_cpy = (char *)str;
  for (size_t i = 0; i < n; i++) {
    *str_cpy++ = c;
  }
  return str;
}