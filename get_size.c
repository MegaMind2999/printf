#include "main.h"

/**
 * get_the_size -Calculates the size
 * @format: the format to print on
 * @i: the args to print
 *
 * Return: Precision.
 */
int get_the_size(const char *format, int *i)
{
	int iterator_i = *i + 1;
	int size = 0;

	if (format[iterator_i] == 'l')
		size = S_LONG;
	else if (format[iterator_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = iterator_i - 1;
	else
		*i = iterator_i;

	return (size);
}
