#include "main.h"
/**
<<<<<<< HEAD
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
return (flags);
}
=======
 * get_flags - calc flags
 * @format: function parameter
 * @i: function parameter
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = curr_i - 1;
	return (flags);
}

>>>>>>> 7a2b1291cc6f47194a36730aa334676eb2e08ab4
