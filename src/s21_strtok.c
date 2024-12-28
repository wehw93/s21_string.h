#include "s21_string.h"
char *s21_strtok(char *str, const char *delimiters) {
  static char *res = s21_NULL;
  if (str != s21_NULL) {
    res = str;
  }
  if (res == s21_NULL) {
    return s21_NULL;
  }
  while (*res != '\0' && s21_strchr(delimiters, *res)) {
    res++;
  }
  if (*res == '\0') {
    return s21_NULL;
  }
  char *start = res;
  while (*res != '\0' && !s21_strchr(delimiters, *res)) {
    res++;
  }
  if (*res != '\0') {
    *res = '\0';
    res++;
  }
  return start;
}
