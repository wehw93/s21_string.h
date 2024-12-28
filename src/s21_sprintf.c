#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

typedef struct Flags {
  int flag_plus;
  int flag_minus;
  int width;
  int tochn;
  int space;
  int flag_h;
  int flag_l;
} Flags;

void reverse(char *str) {
  int len = s21_strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}

void check_format(char buffer[], char **str, Flags flag, int number_len,
                  int *len2) {
  int padding = 0, nulls = 0;
  if (flag.tochn >= number_len) {
    nulls = flag.tochn - number_len;
  }
  int total_len = number_len + nulls;
  if (flag.width > total_len) {
    padding = flag.width - total_len;
  }

  if (flag.flag_minus) {
    memset(*str, '0', nulls);
    *str += nulls;
    strncpy(*str, buffer, number_len);
    *str += number_len;
    memset(*str, ' ', padding);
    *str += padding;
  } else {
    if (flag.space && buffer[0] != '-' && flag.width > flag.tochn) {
      **str = ' ';
      (*str)--;
      (*len2)--;
    }
    memset(*str, ' ', padding);
    *str += padding;
    if (flag.flag_plus && buffer[0] == '0') {
      padding--;
      (*str)--;
      **str = '+';
      (*str)++;
      (*len2)++;
    }

    memset(*str, '0', nulls);
    *str += nulls;
    if (flag.tochn >= number_len) {
      if (buffer[0] == '-') {
        buffer[0] = '0';
        **str = '-';
        (*str)++;
        (*len2)++;
      }
    }

    strncpy(*str, buffer, number_len);
    *str += number_len;
  }
  *len2 += number_len + padding + nulls;
}

int parse_chislo(const char **ptr) {
  int width = 0;
  while (isdigit(**ptr)) {
    width = width * 10 + (**ptr - '0');
    (*ptr)++;
  }
  return width;
}

int sprintf_d(char *str, long nums) {
  long val = nums;
  int count = 0;
  char str2[12] = {0};
  char *original = str2;
  char *ptr = str2;

  if (nums == 0) {
    *ptr++ = '0';
    count++;
  }
  while (labs(nums) > 0) {
    *ptr++ = labs(nums) % 10 + '0';
    nums /= 10;
    count++;
  }
  if (val < 0) {
    *ptr++ = '-';
    count++;
  }

  *ptr = '\0';
  reverse(original);

  for (int i = 0; i < count; i++) {
    *str++ = original[i];
  }

  return count;
}

void format_d(va_list *vlist, char **str, const char **ptr, int *len2,
              Flags flag) {
  (*ptr)++;
  long val;
  if (flag.flag_h) {
    val = (short)va_arg(*vlist, int);
  } else if (flag.flag_l) {
    val = va_arg(*vlist, long);
  } else {
    val = va_arg(*vlist, int);
  }
  char buffer[50] = {0};
  int number_len = 0;
  if (flag.space && val >= 0) {
    **str = ' ';
    (*str)++;
    (*len2)++;
  }
  if (flag.flag_plus && val >= 0) {
    buffer[number_len++] = '+';
  }

  number_len += sprintf_d(buffer + number_len, val);

  check_format(buffer, str, flag, number_len, len2);
}

int sprintf_u(char *str, long nums) {
  int count = 0;
  char str2[12] = {0};
  char *original = str2;
  char *ptr = str2;

  if (nums == 0) {
    *ptr++ = '0';
    count++;
  }

  while (nums > 0) {
    *ptr++ = nums % 10 + '0';
    nums /= 10;
    count++;
  }

  *ptr = '\0';
  reverse(original);

  for (int i = 0; i < count; i++) {
    *str++ = original[i];
  }

  return count;
}

void format_u(va_list *vlist, char **str, const char **ptr, int *len2,
              Flags flag) {
  (*ptr)++;
  long val;
  if (flag.flag_h) {
    val = (unsigned short)va_arg(*vlist, unsigned int);
  } else if (flag.flag_l) {
    val = va_arg(*vlist, unsigned long);
  } else {
    val = va_arg(*vlist, unsigned int);
  }
  char buffer[50] = {0};
  int number_len = 0;

  number_len += sprintf_u(buffer + number_len, val);

  check_format(buffer, str, flag, number_len, len2);
}

void format_c(va_list *vlist, char **str, const char **ptr, int *len2,
              Flags flag) {
  (*ptr)++;
  char buffer[5] = {0};
  int utf_len = 0;

  if (flag.flag_l) {
    wchar_t ch_l = va_arg(*vlist, wchar_t);
    utf_len = wctomb(buffer, ch_l);
  } else {
    char ch = (char)va_arg(*vlist, int);
    buffer[0] = ch;
    utf_len = 1;
  }
  check_format(buffer, str, flag, utf_len, len2);
}

void format_s(va_list *vlist, char **str, const char **ptr, int *len2,
              Flags flag) {
  (*ptr)++;
  const char *input_str = va_arg(*vlist, char *);
  if (!input_str) input_str = "(null)";

  int input_len = s21_strlen(input_str);
  int precision = flag.tochn ? flag.tochn : input_len;

  if (precision < input_len) {
    input_len = precision;
  }

  int padding = (flag.width > input_len) ? flag.width - input_len : 0;

  if (!flag.flag_minus) {
    if (flag.tochn == -1) {
      for (int i = 0; i < padding - 1; i++) {
        *(*str)++ = ' ';
        (*len2)++;
      }
    } else {
      for (int i = 0; i < padding; i++) {
        *(*str)++ = ' ';
        (*len2)++;
      }
    }
  }

  for (int i = 0; i < input_len; i++) {
    *(*str)++ = input_str[i];
    (*len2)++;
  }

  if (flag.flag_minus) {
    for (int i = 0; i < padding; i++) {
      *(*str)++ = ' ';
      (*len2)++;
    }
  }
}

int sprintf_f(char *str, double value, Flags flag) {
  bool neg = value < 0;
  bool zero_neg = signbit(value);
  if (neg) value = -value;
  if ((zero_neg) && value == 0) value = -value;

  long long whole_part = (long long)value;
  double fractional_part = value - whole_part;

  char buffer[100] = {0};
  int idx = 0;
  int count = 0;

  if ((neg) || ((zero_neg) && value == 0)) {
    buffer[idx++] = '-';
    count++;
  }

  if (whole_part == 0 && value == 0.0) {
    buffer[idx++] = '0';
    count++;
  } else {
    char temp[20];
    if (whole_part == 0) {
      buffer[idx++] = '0';
      count++;
    } else {
      int temp_idx = 0;
      while (whole_part > 0) {
        temp[temp_idx++] = (whole_part % 10) + '0';
        whole_part /= 10;
      }
      for (int i = temp_idx - 1; i >= 0; i--) {
        buffer[idx++] = temp[i];
        count++;
      }
    }
  }
  if (flag.tochn != -1) {
    buffer[idx++] = '.';
    count++;
  }

  int precision = flag.tochn ? flag.tochn : 6;
  fractional_part *= pow(10, precision);
  long long fractional_as_int = (long long)round(fractional_part);
  long long temp_fraction = fractional_as_int;
  if (temp_fraction == 0) {
    for (int i = 0; i < precision; i++) {
      buffer[idx++] = '0';
      count++;
    }
  } else {
    int fractional_digits = 0;
    while (temp_fraction > 0) {
      temp_fraction /= 10;
      fractional_digits++;
    }
    for (int i = 0; i < precision - fractional_digits; i++) {
      buffer[idx++] = '0';
      count++;
    }
  }

  char temp[20];
  int temp_idx = 0;
  // if (fractional_as_int == 0) {
  // temp[temp_idx++] = '0';
  //} else {
  while (fractional_as_int > 0) {
    temp[temp_idx++] = (fractional_as_int % 10) + '0';
    fractional_as_int /= 10;
  }
  for (int i = temp_idx - 1; i >= 0; i--) {
    buffer[idx++] = temp[i];
    count++;
  }
  //}

  for (int i = 0; i < idx; i++) {
    str[i] = buffer[i];
  }
  str[idx] = '\0';

  return count;
}

void format_f(va_list *vlist, char **str, const char **ptr, int *len2,
              Flags flag) {
  (*ptr)++;
  double val = va_arg(*vlist, double);
  char buffer[100];
  if (flag.space && val >= 0) {
    **str = ' ';
    (*str)++;
    (*len2)++;
  }
  int number_len = sprintf_f(buffer, val, flag);
  flag.tochn = 0;
  check_format(buffer, str, flag, number_len, len2);
}

int s21_sprintf(char *str, const char *format, ...) {
  const char *ptr = format;
  int len2 = 0;
  Flags flag = {0, 0, 0, 0, 0, 0, 0};
  va_list vlist;
  va_start(vlist, format);

  while (*ptr != '\0') {
    flag.flag_plus = 0;
    flag.flag_minus = 0;
    // flag.width = 0;
    flag.tochn = 0;
    flag.space = 0;
    flag.flag_h = 0;
    flag.flag_l = 0;
    if (*ptr != '%') {
      *str++ = *ptr++;
      len2++;
    } else {
      ptr++;
      if (*ptr == '+') {
        flag.flag_plus = 1;
        ptr++;
      }
      if (*ptr == '-') {
        flag.flag_minus = 1;
        ptr++;
      }
      if (*ptr == ' ') {
        flag.space = 1;
        ptr++;
      }
      flag.width = parse_chislo(&ptr);
      if (*ptr == '.') {
        ptr++;
        flag.tochn = parse_chislo(&ptr);
        flag.tochn = flag.tochn ? flag.tochn : -1;
      }
      if (*ptr == 'h') {
        ptr++;
        flag.flag_h = 1;
      }
      if (*ptr == 'l') {
        ptr++;
        flag.flag_l = 1;
      }
      if (*ptr == '%') {
        *str++ = '%';
        ptr++;
        len2++;
      }
      if (*ptr == 'd') {
        format_d(&vlist, &str, &ptr, &len2, flag);
      }
      if (*ptr == 'c') {
        format_c(&vlist, &str, &ptr, &len2, flag);
      }
      if (*ptr == 's') {
        format_s(&vlist, &str, &ptr, &len2, flag);
      }
      if (*ptr == 'f') {
        format_f(&vlist, &str, &ptr, &len2, flag);
      }
      if (*ptr == 'u') {
        format_u(&vlist, &str, &ptr, &len2, flag);
      }
    }
  }

  *str = '\0';
  va_end(vlist);
  return len2;
}
