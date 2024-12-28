#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int counter = 0, eof = 0;
  while (*str1 != '\0') {
    const char *temp = str2;
    while (*temp != '\0') {
      if (*str1 == *temp) {
        eof = 1;
        break;
      }
      temp++;
    }
    if (eof) break;
    counter++;
    str1++;
  }
  return counter;
}