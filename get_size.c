#include "main.h"
/**
 * get_size – Calculate the size of casting argument
 * @format: a string in which to print the arguments
 * @n: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *n)
{
int curr_n = *n + 1;
int size = 0;
if (format[curr_n] == 'n')
size = S_LONG;
else if (format[curr_n] == 'h')
size = S_SHORT;
if (size == 0)
*n = curr_n - 1;
else
*n = curr_n;
return (size);
}
