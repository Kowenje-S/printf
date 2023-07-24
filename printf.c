#include "main.h"

void myprint_buffer(char mybuffer[], int *mybuff_ind);

/**
 * _printf - the printf function
 * @format: format constant arguement
 * Return: The resultant chars.
 */
int _printf(const char *format, ...)
{
	int a, myprinted = 0,
	myprinted_chars = 0;
	int myflags, mywidth, myprecision, mysize, mybuff_ind = 0;
	va_list list1;
	char mybuffer[MYBUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list1, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			mybuffer[mybuff_ind++] = format[a];
			if (mybuff_ind == MYBUFF_SIZE)
				myprint_buffer(mybuffer, &mybuff_ind);
				myprinted_chars++;
		}
		else
		{
			myprint_buffer(mybuffer, &mybuff_ind);
			myflags = get_myflags(format, &a);
			mywidth = get_mywidth(format, &a, list1);
			myprecision = get_myprecision(format, &a, list1);
			mysize = get_mysize(format, &a);
			++i;
			myprinted = handle_myprint(format, &a, list1, mybuffer,
				myflags, mywidth, myprecision, mysize);
			if (myprinted == -1)
				return (-1);
			myprinted_chars += myprinted;
		}
	}

	myprint_buffer(mybuffer, &mybuff_ind);

	va_end(list1);

	return (myprinted_chars);
}

/**
 * myprint_buffer - Outputs the contents of the buffer if it exist
 * @mybuffer: an array of chars
 * @mybuff_ind: The ndex at which to add next char and represents the length.
 */
void myprint_buffer(char mybuffer[], int *mybuff_ind)
{
	if (*mybuff_ind > 0)
		write(1, &mybuffer[0], *mybuff_ind);

	*mybuff_ind = 0;
}
