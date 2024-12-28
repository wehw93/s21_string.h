#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *pointer = s21_NULL;
  while (*str1 != '\0') {
    const char *temp = str2;
    while (*temp != '\0') {
      if (*str1 == *temp) {
        pointer = (char *)str1;
        break;
      }
      temp++;
    }
    if (pointer != s21_NULL) break;
    str1++;
  }
  return pointer;
}