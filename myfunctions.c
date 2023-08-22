#include "main.h"

/**
 * print_unsignd - Printing unsigned number
 * @types: args
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed.
 */
int print_unsignd(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_in_octal - Prints an unsigned number in octal
 * @types: args
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_in_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadeci - Prints an unsigned number in hexa
 * @types: args
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: the width
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_hexadeci(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexadeci_upper - Prints an unsigned number in upper hexa
 * @types: args
 * @buffer: buffer to be used in printing
 * @flags:  the active flags
 * @width: the width
 * @precision: the Precision
 * @size: the size
 * Return: count of the chars printed
 */
int print_hexadeci_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hex - Prints a hexa numbers in lower or upper
 * @types: args
 * @map_to: Array of values to map the number to
 * @buffer: buffer to be used in printing
 * @flags:  the active flags
 * @flag_ch: the active flags char
 * @width: the width
 * @precision: the Precision
 * @size: the size
 * @size: Size of it
 * Return: count of the chars printed
 */
int print_hex(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}
