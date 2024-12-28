#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed = s21_NULL;
  if (src != s21_NULL) {
    int lenSrc = s21_strlen(src);
    int start = 0, end = lenSrc - 1;
    while (start < lenSrc &&
           ((trim_chars && s21_strchr(trim_chars, src[start]) != s21_NULL) ||
            (!trim_chars && !s21_trim_null(src[start])))) {
      start++;
    }
    while (end >= start &&
           ((trim_chars && s21_strchr(trim_chars, src[end]) != s21_NULL) ||
            (!trim_chars && !s21_trim_null(src[end])))) {
      end--;
    }
    int new_len = (end - start + 1);
    trimmed = (char *)calloc(new_len + 1, sizeof(char));
    if (trimmed != s21_NULL) {
      s21_strncpy(trimmed, src + start, new_len);
    }
  }
  return (void *)trimmed;
}

int s21_trim_null(char chr) {
  return (chr < 9 || (chr > 13 && chr != 32)) ? 1 : 0;
}