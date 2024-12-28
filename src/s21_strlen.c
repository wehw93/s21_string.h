#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;
  if (str != s21_NULL) {
    while (*str != '\0') {
      str++;
      lenght++;
    }
  }
  return lenght;
}