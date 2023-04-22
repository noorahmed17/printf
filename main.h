#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags,
int width, int precision, int size);
int get_flags(const char *format, int *x);
int get_width(const char *format, int *j, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *n);
/*functions*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
int handle_write_char(char c, char buf[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int wi, int pre, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int leth,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int index,
char buffer[],
int flags, int width, int precision, int size);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


/*flags*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/*sizes*/
#define S_LONG 2
#define S_SHORT 1

#endif
