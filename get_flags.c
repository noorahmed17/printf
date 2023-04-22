#include "main.h"
/**
 * get_flags - turns on flags
 * @format: Formatted string in which to print the arguments
 * @x: character.
 * Return: Flags:
 */
int get_flags(const char *format, int *x)
{
/* - + 0 # ' ' */
int y, curr_x;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (curr_x = *x + 1; format[curr_x] != '\0'; curr_x++)
{
for (y = 0; FLAGS_CH[y] != '\0'; y++)
if (format[curr_x] == FLAGS_CH[y])
{
flags |= FLAGS_ARR[j];
break;
}
if (FLAGS_CH[y] == 0)
break;
}
*x = curr_x - 1;
return(flags);
}
