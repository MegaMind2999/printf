#include "main.h"

/**
 * get_the_width - get the width
 * @format: the format to print on.
 * @i: the args to print
 * @list: list of arguments.
 * Return: width.
 */
int get_the_width(const char *format, int *i, va_list list)
{
	int iterator_i;
	int width = 0;

	for (iterator_i = *i + 1; format[iterator_i] != '\0'; iterator_i++)
	{
		if (is_digit(format[iterator_i]))
		{
			width *= 10;
			width += format[iterator_i] - '0';
		}
		else if (format[iterator_i] == '*')
		{
			iterator_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = iterator_i - 1;

	return (width);
}
