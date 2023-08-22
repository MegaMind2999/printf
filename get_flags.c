#include "main.h"

/**
 * get_the_flag - return active flags
 * @format: format to print in
 * @i: take a parameter.
 * Return: Flags:
 */
int get_the_flag(const char *format, int *i)
{
	int j, iterator_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (iterator_i = *i + 1; format[iterator_i] != '\0'; iterator_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[iterator_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = iterator_i - 1;

	return (flags);
}

