#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf
 * @format: the format.
 * Return: the number of Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars_count = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFER_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars_count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_the_flag(format, &i);
			width = get_the_width(format, &i, list);
			precision = get_the_precision(format, &i, list);
			size = get_the_size(format, &i);
			++i;
			printed = print_handler(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars_count += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars_count);
}

/**
 * print_buffer - Prints the buffer
 * @buffer: chars
 * @buff_ind: Index where to add next char
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
