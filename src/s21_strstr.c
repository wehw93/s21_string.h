#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (!s21_strncmp(needle, "\0", 1)) {
    return (char *)haystack;
  }

  s21_size_t needle_len = s21_strlen(needle);
  while (*haystack) {
    if (s21_strlen(haystack) < needle_len) {
      break;
    }

    if (!s21_strncmp(haystack, needle, needle_len)) {
      return (char *)haystack;
    }

    haystack++;
  }

  return s21_NULL;
}
