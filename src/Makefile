CC=gcc -std=c11
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS =  -lgcov --coverage
TEST_SOURCES = $(wildcard tests/*.c)
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIB_NAME = s21_string.a
LIBS = -lcheck -lm  -lsubunit 

all: s21_string.a test gcov_report

s21_string.a: $(OBJS)
	ar rs $(LIB_NAME) $^
	rm -rf *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TEST_SOURCES) $(SRCS) $(LIB_NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(GCOV_FLAGS) $(LIBS)
	./test

gcov_report: test
	lcov -t "gcov_test" -o gcov_test.info -c -d .
	genhtml -o report gcov_test.info
	
format-check:
	clang-format  -n *.c *.h tests/*.c tests/*.h

format:
	clang-format  -i *.c *.h tests/*.c tests/*.h

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test

rebuild: clean all

clean:
	rm -fr *.o *.a test test.dSYM/ *.gcda *.gcno report/ test.info *.html gcov_test.info
