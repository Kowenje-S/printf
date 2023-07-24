#include "main.h"

/**
 * is_printable - a function that evaluates if a char is printable
 * @c: the char to evaluate.
 *
 * Return: 1 if c is printable, 0 if not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - the function that append ascci in hexadecimal code to buffer
 * @buffer: an array of chars.
 * @i: the Index from where  to start appending.
 * @ascii_code: the ASSCI CODE.
 * Return:  3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - the function that verifies if a char is a digit
 * @c: the Char to  evaluate
 *
 * Return: 1 if c is a digit, 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - the function that casts a number to the specified size
 * @num: the number to be casted.
 * @size: the number indicating the type to be casted.
 *
 * Return: the casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - the function that casts a number to the specified size
 * @num: the number to be casted
 * @size: the number indicating the type to be casted
 *
 * Return: the casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

