#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = (const unsigned char *)str;
  unsigned char uc = (unsigned char)c;
  void *result = s21_NULL;
  size_t i = 0;

  while (i < n && result == s21_NULL) {
    if (p[i] == uc) {
      result = (void *)(p + i);
    }
    i++;
  }
  return result;
}
