#include "main.h"
/**
 * _printf - printf function
 * @format: function parameter
 * @...: variable arguments
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_end = 0;
	va_list list;
	char buffer[BUFF_SIZE]; /*1024*/

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_end++] = format[i];
			if (buff_end == BUFF_SIZE)
				print_buffer(buffer, &buff_end);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_end);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags,
					width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_end);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - print contents of buffer
 * @buffer: function parameter
 * @buff_end: function parameter
 */
void print_buffer(char buffer[], int *buff_end)
{
	if (*buff_end > 0)
		write(1, &buffer[0], *buff_end);
	*buff_end = 0;
}
