#include "s21_string.h"
void reverse_str(char *str);
char *s21_strrchr(const char *str, int c) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  const char *res = s21_NULL;
  while (*str) {
    if (*str == (char)c) {
      res = str;
    }
    str++;
  }
  if ((char)c == (char)'\0') {
    return (char *)str;
  }
  return (char *)res;
}
