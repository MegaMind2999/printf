#include "main.h"

/**
 * is_the_char_printable - check if a char is printable
 * @c: Char to be evaluated.
 * Return: 1 or 0
 */
int is_the_char_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hex_code - Append ascci in hexadecimal
 * @buffer: Array of chars.
 * @i: Index to start.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hex_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 or 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - changing size of the number
 * @num: Number.
 * @size: size to cast to.
 * Return: new size
 */
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsignd - changing size of the number
 * @num: Number
 * @size: size to cast to.
 * Return: new size of num
 */
long int convert_size_unsignd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
