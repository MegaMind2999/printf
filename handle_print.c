#include "main.h"
/**
 * print_handler - Print handler
 * @fmt: the format to print on.
 * @list: the args to print
 * @ind: ind.
 * @buffer: buffer to be used in printing.
 * @flags: the active flags
 * @width: the width.
 * @precision: the Precision
 * @size: the size
 * Return: 1 or 2;
 */
int print_handler(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars_count = -1;
	fmt_obj fmt_types[] = {
		{'c', print_chr}, {'s', print_str}, {'%', print_percent_sign},
		{'i', print_intger}, {'d', print_intger}, {'b', print_bin},
		{'u', print_unsignd}, {'o', print_in_octal}, {'x', print_hexadeci},
		{'X', print_hexadeci_upper}, {'p', print_the_ptr}, {'S', print_non_printable_chars},
		{'r', print_in_reverse}, {'R', print_rot13_string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars_count);
}
