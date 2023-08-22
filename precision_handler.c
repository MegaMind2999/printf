#include "main.h"

/**
 * get_the_precision - Calculating the precision for printing
 * @format: format to print in
 * @i: List of args to be printed.
 * @list: args.
 * Return: num.
 */
int get_the_precision(const char *format, int *i, va_list list)
{
	int iterator_i = *i + 1;
	int precision = -1;

	if (format[iterator_i] != '.')
		return (precision);

	precision = 0;

	for (iterator_i += 1; format[iterator_i] != '\0'; iterator_i++)
	{
		if (is_digit(format[iterator_i]))
		{
			precision *= 10;
			precision += format[iterator_i] - '0';
		}
		else if (format[iterator_i] == '*')
		{
			iterator_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = iterator_i - 1;

	return (precision);
}
