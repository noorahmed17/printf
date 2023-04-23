#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * handle_print - Prints an argument based on its type
 * @fm: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Cal active flags
 * @wi: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fm, int *ind, va_list list, char buffer[]
, int flags, int wi, int precision, int size)
{
int i, unknow_len = 0, printed_chars = -1;
fmt_t fmt_type[] =
{
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (i = 0; fmt_type[i].fm != '\0'; i++)
if (fm[*ind] == fmt_type[i].fm)
return (fmt_type[i].fn(list, buffer, flags, wi, precision, size));
if (fmt_type[i].fm == '\0')
{
if (fm[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fm[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (wi)
{
--(*ind);
while (fm[*ind] != ' ' && fm[*ind] != '%')
--(*ind);
if (fm[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fm[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}
