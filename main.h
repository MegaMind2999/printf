#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFER_SIZE 1024
#define S_LONG 2
#define S_SHORT 1

#define F_ZERO 1
#define F_SPACE 2
#define F_MINUS 4
#define F_HASH 8
#define F_PLUS 16


/**
 * struct fmt - Structure
 * @fmt: The format.
 * @fn: The function with this format.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_obj - Structure object
 * @fmt: The format to parse.
 * @fm_t: The function with this format.
 */
typedef struct fmt fmt_obj;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int print_chr(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_sign(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadeci_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_intger(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsignd(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_in_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadeci(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_the_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_the_flag(const char *format, int *i);
int get_the_size(const char *format, int *i);
int get_the_width(const char *format, int *i, va_list list);
int get_the_precision(const char *format, int *i, va_list list);

int print_in_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_chr(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_the_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_mynum(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_the_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsignd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);

long int convert_size_num(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);

int is_the_char_printable(char);
int append_hex_code(char, char[], int);
int is_digit(char);


#endif
