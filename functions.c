#include "main.h"

/**
 * print_chr - Printing a char
 * @types: args
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: the Width
 * @precision: the Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_chr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_chr(c, buffer, flags, width, precision, size));
}
/**
 * print_str - Printing a string
 * @types: args
 * @buffer: Buffer array to handle the print
 * @flags:  Calculates the active flags
 * @width: the width.
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent_sign - Prints a percent sign
 * @types: args
 * @buffer: Buffer to handle the print
 * @flags: active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_percent_sign(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_intger - Printing int
 * @types: args
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_intger(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_the_number(is_negative, i, buffer,
	flags, width, precision, size));
}

/**
 * print_bin - Prints an unsigned number
 * @types: args
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: count of char printed.
 */
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

