#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_length = s21_strlen(src);
  if (src_length < n) {
    s21_memset(dest + src_length, '\0', n - src_length);
    s21_memcpy(dest, src, src_length);
  } else {
    s21_memcpy(dest, src, n);
  }
  return dest;
}