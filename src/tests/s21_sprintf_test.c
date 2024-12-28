// #include <float.h>
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #include "test.h"
// #define BUFF_SIZE 1024

// START_TEST(s21_sprintf_test) {
//   char *res1 = calloc(100, sizeof(char));
//   char *res2 = calloc(100, sizeof(char));

//   ck_assert_int_eq(s21_sprintf(res1, "hello"), sprintf(res2, "hello"));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %d", 105),
//                    sprintf(res2, "Simple value %d", 105));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %ld", 12345678912),
//                    sprintf(res2, "Simple value %ld", 12345678912));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %hd", 123456),
//                    sprintf(res2, "Simple value %hd", 123456));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %hu", 123456),
//                    sprintf(res2, "Simple value %hu", 123456));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %lu", 12345678912),
//                    sprintf(res2, "Simple value %lu", 12345678912));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value % d", 105),
//                    sprintf(res2, "Simple value % d", 105));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value % d", -105),
//                    sprintf(res2, "Simple value % d", -105));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value % f", 105.3),
//                    sprintf(res2, "Simple value % f", 105.3));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %d", 0),
//                    sprintf(res2, "Simple value %d", 0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %u", 0),
//                    sprintf(res2, "Simple value %u", 0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "Simple value %u", 6),
//                    sprintf(res2, "Simple value %u", 6));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hell%% %d", 105),
//                    sprintf(res2, "hell%% %d", 105));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %u", 105),
//                    sprintf(res2, "hello %u", 105));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %s", ">>Huba<<"),
//                    sprintf(res2, "hello %s", ">>Huba<<"));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %.3s", ">>Huba<<"),
//                    sprintf(res2, "hello %.3s", ">>Huba<<"));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %f", 2323.324),
//                    sprintf(res2, "hello %f", 2323.324));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %.4d", 3),
//                    sprintf(res2, "hello %.4d", 3));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %+d", -140),
//                    sprintf(res2, "hello %+d", -140));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %+-5d", -140),
//                    sprintf(res2, "hello %+-5d", -140));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %-12d", 140),
//                    sprintf(res2, "hello %-12d", 140));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "char %c", 'c'),
//                    sprintf(res2, "char %c", 'c'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "char %lc", L'c'),
//                    sprintf(res2, "char %lc", L'c'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "hello %-12c", 'h'),
//                    sprintf(res2, "hello %-12c", 'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "%+d he%-5cllo %c", 20, 'e', 'h'),
//                    sprintf(res2, "%+d he%-5cllo %c", 20, 'e', 'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(
//       s21_sprintf(res1, "%s he%-5cll%-5so %c", "myremari", 'e', "agaga",
//       'h'), sprintf(res2, "%s he%-5cll%-5so %c", "myremari", 'e', "agaga",
//       'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(
//       s21_sprintf(res1, "%f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'),
//       sprintf(res2, "%f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(
//       s21_sprintf(res1, "%.5f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'),
//       sprintf(res2, "%.5f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(
//       s21_sprintf(res1, "%f he", 15.000000005),
//       sprintf(res2, "%f he", 15.00000005));  // в этом тесте segmentation
//       fault
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "%.3f he", -15.5),
//                    sprintf(res2, "%.3f he", -15.5));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(s21_sprintf(res1, "%.3f he", -15.0005),
//                    sprintf(res2, "%.3f he", -15.0005));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(
//       s21_sprintf(res1, "%.8f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'),
//       sprintf(res2, "%.8f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   ck_assert_int_eq(
//       s21_sprintf(res1, "%2f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'),
//       sprintf(res2, "%2f he%-5cll%-5so %c", 15.5, 'e', "agaga", 'h'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   char buffer10[100];
//   char buffer_cpy10[100];
//   for (int j = 0; j < 100; j++) {
//     short int i = rand() % 10000;
//     sprintf(buffer10, "%hd", i);
//     s21_sprintf(buffer_cpy10, "%hd", i);

//     ck_assert_str_eq(buffer10, buffer_cpy10);
//   }

//   char std_buffer4[512] = {0};
//   char custom_buffer4[512] = {0};

//   const char *formats4[] = {"%d", "%+d", "%d", "%-d", "%c", "%u"};

//   int int_values3[] = {5, 1, -1, 42, -42, 12345, -12345};

//   for (size_t i = 0; i < sizeof(formats4) / sizeof(formats4[0]); i++) {
//     const char *format = formats4[i];

//     for (size_t j = 0; j < sizeof(int_values3) / sizeof(int_values3[0]); j++)
//     {
//       memset(std_buffer4, 0, sizeof(std_buffer4));
//       memset(custom_buffer4, 0, sizeof(custom_buffer4));
//       sprintf(std_buffer4, format, 2, int_values3[j]);
//       s21_sprintf(custom_buffer4, format, 2, int_values3[j]);
//       ck_assert_str_eq(std_buffer4, custom_buffer4);
//     }
//   }

//   // Тест на строку
//   ck_assert_int_eq(s21_sprintf(res1, "hello"), sprintf(res2, "hello"));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на целое число
//   ck_assert_int_eq(s21_sprintf(res1, "number: %d", 123),
//                    sprintf(res2, "number: %d", 123));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на целое число с отрицательным значением
//   ck_assert_int_eq(s21_sprintf(res1, "negative: %d", -456),
//                    sprintf(res2, "negative: %d", -456));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на строку с пробелами
//   ck_assert_int_eq(s21_sprintf(res1, "greeting: %s", "hello world"),
//                    sprintf(res2, "greeting: %s", "hello world"));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на спецификатор %f (с плавающей точкой)
//   ck_assert_int_eq(s21_sprintf(res1, "pi: %.2f", 3.14159),
//                    sprintf(res2, "pi: %.2f", 3.14159));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на спецификатор %s с пустой строкой
//   ck_assert_int_eq(s21_sprintf(res1, "empty string: '%s'", ""),
//                    sprintf(res2, "empty string: '%s'", ""));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на спецификатор %c (символ)
//   ck_assert_int_eq(s21_sprintf(res1, "char: %c", 'A'),
//                    sprintf(res2, "char: %c", 'A'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Тест на спецификатор %lu (беззнаковое длинное число)
//   ck_assert_int_eq(
//       s21_sprintf(res1, "unsigned long: %lu", (unsigned long)123456789),
//       sprintf(res2, "unsigned long: %lu", (unsigned long)123456789));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for zero value
//   ck_assert_int_eq(s21_sprintf(res1, "value: %d", 0),
//                    sprintf(res2, "value: %d", 0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for negative zero (though this is same as zero in C)
//   ck_assert_int_eq(s21_sprintf(res1, "negative zero: %+d", 0),
//                    sprintf(res2, "negative zero: %+d", 0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for negative number
//   ck_assert_int_eq(s21_sprintf(res1, "negative: %d", -123),
//                    sprintf(res2, "negative: %d", -123));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for negative value with explicit sign
//   ck_assert_int_eq(s21_sprintf(res1, "negative with sign: %+d", -123),
//                    sprintf(res2, "negative with sign: %+d", -123));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for large negative number
//   ck_assert_int_eq(s21_sprintf(res1, "large negative: %d", -123456789),
//                    sprintf(res2, "large negative: %d", -123456789));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for zero value with %u (unsigned)
//   ck_assert_int_eq(s21_sprintf(res1, "unsigned zero: %u", 0),
//                    sprintf(res2, "unsigned zero: %u", 0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for large unsigned value
//   ck_assert_int_eq(s21_sprintf(res1, "large unsigned: %u", 123456789),
//                    sprintf(res2, "large unsigned: %u", 123456789));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for floating-point zero value
//   ck_assert_int_eq(s21_sprintf(res1, "float zero: %.2f", 0.0),
//                    sprintf(res2, "float zero: %.2f", 0.0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for negative floating-point value
//   ck_assert_int_eq(s21_sprintf(res1, "negative float: %.2f", -3.14),
//                    sprintf(res2, "negative float: %.2f", -3.14));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for negative large floating-point value
//   ck_assert_int_eq(s21_sprintf(res1, "large negative float: %.2f",
//   -12345.6789),
//                    sprintf(res2, "large negative float: %.2f", -12345.6789));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for zero character
//   ck_assert_int_eq(s21_sprintf(res1, "zero char: %c", '\0'),
//                    sprintf(res2, "zero char: %c", '\0'));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for negative character (non-printable char)
//   ck_assert_int_eq(s21_sprintf(res1, "negative char: %c", -1),
//                    sprintf(res2, "negative char: %c", -1));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for unsigned zero
//   ck_assert_int_eq(s21_sprintf(res1, "unsigned zero: %u", 0),
//                    sprintf(res2, "unsigned zero: %u", 0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for unsigned negative value (should treat it as large positive)
//   ck_assert_int_eq(s21_sprintf(res1, "unsigned negative: %u", -1),
//                    sprintf(res2, "unsigned negative: %u", -1));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for unsigned large value
//   ck_assert_int_eq(s21_sprintf(res1, "unsigned large: %lu", 4294967295),
//                    sprintf(res2, "unsigned large: %lu", 4294967295));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for floating-point negative zero
//   ck_assert_int_eq(s21_sprintf(res1, "negative float zero: %.2f", -0.0),
//                    sprintf(res2, "negative float zero: %.2f", -0.0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   // Test for zero floating point with %f
//   ck_assert_int_eq(s21_sprintf(res1, "zero float: %f", 0.0),
//                    sprintf(res2, "zero float: %f", 0.0));
//   ck_assert_str_eq(res1, res2);
//   res1 = memset(res1, 0, 100);
//   res2 = memset(res2, 0, 100);

//   char std_buffer2[512] = {0};
//   char custom_buffer2[512] = {0};

//   const char *formats2[] = {"|%.6d|\n", "|% 10.9d|\n"};

//   double int_values[] = {0, 1, -1, 42, -42, 12345, -12345, -67567};

//   for (size_t i = 0; i < sizeof(formats2) / sizeof(formats2[0]); i++) {
//     const char *format = formats2[i];

//     for (size_t j = 0; j < sizeof(int_values) / sizeof(int_values[0]); j++) {
//       memset(std_buffer2, 0, sizeof(std_buffer2));
//       memset(custom_buffer2, 0, sizeof(custom_buffer2));
//       sprintf(std_buffer2, format, 2, int_values[j]);
//       s21_sprintf(custom_buffer2, format, 2, int_values[j]);
//       ck_assert_str_eq(std_buffer2, custom_buffer2);
//     }
//   }

//   char std_buffer1[512] = {0};
//   char custom_buffer1[512] = {0};

//   const char *formats1[] = {"%f", "%.f", "%.2f"};

//   double double_values[] = {0, 1.1, -1.4, 42.24, -42.10, 12345.1, -12345.1};

//   for (size_t i = 0; i < sizeof(formats1) / sizeof(formats1[0]); i++) {
//     const char *format = formats1[i];

//     for (size_t j = 0; j < sizeof(double_values) / sizeof(double_values[0]);
//          j++) {
//       memset(std_buffer1, 0, sizeof(std_buffer1));
//       memset(custom_buffer1, 0, sizeof(custom_buffer1));
//       sprintf(std_buffer1, format, 2, double_values[j]);
//       s21_sprintf(custom_buffer1, format, 2, double_values[j]);
//       ck_assert_str_eq(std_buffer1, custom_buffer1);
//     }
//   }

//   char std_buffer[512] = {0};
//   char custom_buffer[512] = {0};
//   const char *formats[] = {"%s",   "%-s",   "%5s",    "%-5s",       "%.3s",
//                            "%.8s", "%8.3s", "%-8.3s", "|% 10.2s|\n"};
//   // const char *formats[] = {"%2.2s"};

//   const char *test_strings[] = {
//       "ИИ", "A", "Test", "Hello world guys",
//       "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do
//       eiusmod " "tempor incididunt ut labore et dolore magna aliqua. Ut enim
//       ad minim " "veniam, quis nostrud exercitation ullamco laboris nisi ut
//       aliquip ex ea " "commodo consequat. Duis aute irure dolor in
//       reprehenderit in voluptate " "velit esse cillum dolore eu fugiat nulla
//       pariatur. Excepteur sint " "occaecat cupidatat non proident, sunt in
//       culpa qui officia deserunt " "mollit anim id est laborum. N more than
//       400 symbols"};

//   for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
//     const char *format = formats[i];

//     for (size_t j = 0; j < sizeof(test_strings) / sizeof(test_strings[0]);
//          j++) {
//       memset(std_buffer, 0, sizeof(std_buffer));
//       memset(custom_buffer, 0, sizeof(custom_buffer));
//       sprintf(std_buffer, format, test_strings[j]);
//       s21_sprintf(custom_buffer, format, test_strings[j]);
//       ck_assert_str_eq(std_buffer, custom_buffer);
//     }
//   }
// }

// END_TEST

// START_TEST(test_zero_values) {
//   char *res1 = calloc(BUFF_SIZE, sizeof(char));
//   char *res2 = calloc(BUFF_SIZE, sizeof(char));

//   // Тесты для нулевых значений
//   ck_assert_int_eq(s21_sprintf(res1, "%d", 0), sprintf(res2, "%d", 0));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%u", 0), sprintf(res2, "%u", 0));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%.6f", 0.0), sprintf(res2, "%.6f",
//   0.0)); ck_assert_str_eq(res1, res2); memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%s", NULL),
//                    sprintf(res2, "%s", (char *)NULL));
//   ck_assert_str_eq(res1, res2);

//   free(res1);
//   free(res2);
// }
// END_TEST

// START_TEST(test_negative_numbers) {
//   char *res1 = calloc(BUFF_SIZE, sizeof(char));
//   char *res2 = calloc(BUFF_SIZE, sizeof(char));

//   ck_assert_int_eq(s21_sprintf(res1, "%d", -123), sprintf(res2, "%d", -123));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%.2f", -123.456),
//                    sprintf(res2, "%.2f", -123.456));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%ld", (long)-987654321),
//                    sprintf(res2, "%ld", (long)-987654321));
//   ck_assert_str_eq(res1, res2);

//   free(res1);
//   free(res2);
// }
// END_TEST

// START_TEST(test_flags_combinations) {
//   char *res1 = calloc(BUFF_SIZE, sizeof(char));
//   char *res2 = calloc(BUFF_SIZE, sizeof(char));

//   ck_assert_int_eq(s21_sprintf(res1, "%+d", 42), sprintf(res2, "%+d", 42));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%10d", -42), sprintf(res2, "%10d",
//   -42)); ck_assert_str_eq(res1, res2); memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%-10d", -42),
//                    sprintf(res2, "%-10d", -42));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%10d", 42), sprintf(res2, "%10d", 42));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "% f", 42.5), sprintf(res2, "%
//   f", 42.5)); ck_assert_str_eq(res1, res2);

//   free(res1);
//   free(res2);
// }
// END_TEST

// START_TEST(test_specifiers_with_modifiers) {
//   char *res1 = calloc(BUFF_SIZE, sizeof(char));
//   char *res2 = calloc(BUFF_SIZE, sizeof(char));

//   ck_assert_int_eq(s21_sprintf(res1, "%hd", (short)12345),
//                    sprintf(res2, "%hd", (short)12345));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%ld", (long)-1234567890),
//                    sprintf(res2, "%ld", (long)-1234567890));
//   ck_assert_str_eq(res1, res2);
//   memset(res1, 0, BUFF_SIZE);
//   memset(res2, 0, BUFF_SIZE);

//   ck_assert_int_eq(s21_sprintf(res1, "%lf", (long double)-123456.789),
//                    sprintf(res2, "%Lf", (long double)-123456.789));
//   ck_assert_str_eq(res1, res2);

//   free(res1);
//   free(res2);
// }
// END_TEST

// Suite *suite_sprintf() {
//   Suite *st = suite_create("\033[45m-=s21_sprintf_test=-\033[0m");
//   TCase *tc_sprintf = tcase_create("s21_sprintf_test");

//   tcase_add_test(tc_sprintf, test_zero_values);
//   tcase_add_test(tc_sprintf, test_negative_numbers);
//   tcase_add_test(tc_sprintf, test_flags_combinations);
//   tcase_add_test(tc_sprintf, test_specifiers_with_modifiers);
//   tcase_add_test(tc_sprintf, s21_sprintf_test);
//   suite_add_tcase(st, tc_sprintf);
//   return st;
// }

#include <limits.h>

#include "test.h"

#define BUFF_SIZE 512

START_TEST(sprintf_d_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 123;
  char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_h) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  char *format = "|%hd|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_d_w) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  char *format = "|%4d|%6d\n";
  int res1 = s21_sprintf(str1, format, x, 6);
  int res2 = sprintf(str2, format, x, 6);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_d_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *format = "|% d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 0;
  char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 6878;
  char *format = "|%1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -315;
  char *format = "|%4d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -14566;
  char *format = "|%.1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 56368;
  char *format = "|%.10d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -67567;
  char *format = "|%.6d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  char *format = "|% 20.15d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned long int x = 123456789000;
  char *format = "|%+ 15.20lu|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ld_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = -12345678900;
  char *format = "|%ld|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '1';
  char *format = "|%c|\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '1';
  char *format = "%-20c\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = 'A';
  char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)c);
  int res2 = sprintf(str2, format, (unsigned long)c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lc_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t ch = L'1';
  char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)ch);
  int res2 = sprintf(str2, format, (unsigned long)ch);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "\0";
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.0s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%-5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%%\n%d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%%%%%% %d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 123.34634;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -4534123.34634;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487.635;
  char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "|%15.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00005;
  char *format = "|%+13f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -94634.452463574563;
  char *format = "|%+010f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 4.1111e-30;
  char *format = "|%40.35f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  char *format = "|%.2f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_d_1);
  tcase_add_test(tc, sprintf_d_2);
  tcase_add_test(tc, sprintf_d_h);
  tcase_add_test(tc, sprintf_d_w);
  tcase_add_test(tc, sprintf_d_3);
  tcase_add_test(tc, sprintf_d_4);
  tcase_add_test(tc, sprintf_d_7);
  tcase_add_test(tc, sprintf_d_8);
  tcase_add_test(tc, sprintf_d_5);
  tcase_add_test(tc, sprintf_d_9);
  tcase_add_test(tc, sprintf_d_10);
  tcase_add_test(tc, sprintf_d_11);
  tcase_add_test(tc, sprintf_d_16);
  tcase_add_test(tc, sprintf_u_2);
  tcase_add_test(tc, sprintf_ld_2);
  tcase_add_test(tc, sprintf_c_1);
  tcase_add_test(tc, sprintf_c_2);
  tcase_add_test(tc, sprintf_c_3);
  tcase_add_test(tc, sprintf_lc_1);
  tcase_add_test(tc, sprintf_s_1);
  tcase_add_test(tc, sprintf_s_2);
  tcase_add_test(tc, sprintf_s_3);
  tcase_add_test(tc, sprintf_s_5);
  tcase_add_test(tc, sprintf_s_6);
  tcase_add_test(tc, sprintf_s_7);
  tcase_add_test(tc, sprintf_s_8);
  tcase_add_test(tc, sprintf_per_1);
  tcase_add_test(tc, sprintf_per_2);
  tcase_add_test(tc, sprintf_f_1);
  tcase_add_test(tc, sprintf_f_2);
  tcase_add_test(tc, sprintf_f_3);
  tcase_add_test(tc, sprintf_f_5);
  tcase_add_test(tc, sprintf_f_6);
  tcase_add_test(tc, sprintf_f_8);
  tcase_add_test(tc, sprintf_f_9);
  tcase_add_test(tc, sprintf_f_12);
  tcase_add_test(tc, sprintf_f_15);
  tcase_add_test(tc, sprintf_f_16);

  suite_add_tcase(s, tc);
  return s;
}
