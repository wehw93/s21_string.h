#include "s21_string.h"

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *res = s21_NULL;
  if (str != s21_NULL) {
    res = (char *)malloc(len + 1);
  }
  if (res != s21_NULL) {
    s21_strncpy(res, str, len + 1);
    res[len] = '\0';
    char *tmp = res;
    while (*tmp != '\0') {
      if ((*tmp >= 'A') && (*tmp <= 'Z')) {
        *tmp = *tmp + 32;
      }
      tmp++;
    }
  }
  return (void *)res;
}
