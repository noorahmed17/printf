#include "main.h"
/**
 * print_unsigned - print a unsigned
 * @types: function parameter
 * @buffer: function parameter
 * @flags: function parameter
 * @width: function parameter
 * @precision: function parameter
 * @size: function parameter
 * Return: printed char
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - print in octal
 * @types: function parameter
 * @buffer: function parameter
 * @flags: function parameter
 * @width: function parameter
 * @precision: function parameter
 * @size: function parameter
 * Return: printed char
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - print in hexadecimal
 * @types: function parameter
 * @buffer: function parameter
 * @flags: function parameter
 * @width: function parameter
 * @precision: function parameter
 * @size: function parameter
 * Return: printed char
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - print in hexadecimal
 * @types: function parameter
 * @buffer: function parameter
 * @flags: function parameter
 * @width: function parameter
 * @precision: function parameter
 * @size: function parameter
 * Return: printed char
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 * print_hexa - print in hexadecimal
 * @types: function parameter
 * @map_to: function parameter
 * @buffer: function parameter
 * @flags: function parameter
 * @flag_ch: function parameter
 * @width: function parameter
 * @precision: function parameter
 * @size: function parameter
 * Return: printed char
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flage_cha;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
