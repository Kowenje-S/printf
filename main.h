#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define MyBUFF_SIZE 1024

/* FLAGS */
#define myF_MINUS 1
#define myF_PLUS 2
#define myF_ZERO 4
#define myF_HASH 8
#define myF_SPACE 16

/* SIZES */
#define myS_LONG 2
#define myS_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list1, char mybuffer[], int myflags,
int mywidth, int myprecision, int mysize);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_my types, char mybuffer[],
	int flags, int mywidth, int myprecision, int mysize);
int print_string(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int print_percent(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

/* Functions to print numbers */
int print_int(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int print_binary(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int print_unsigned(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int print_octal(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int print_hexadecimal(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int print_hexa_upper(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

int print_hexa(va_list mytypes, char map_to[],
char mybuffer[], int myflags, char myflag_ch,
int mywidth, int myprecision, int mysize);

/* Function to print non printable characters */
int print_non_printable(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

/* Funcion to print memory address */
int print_pointer(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list1);
int get_precision(const char *format, int *i, va_list list1);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

/*Function to print a string in rot 13*/
int print_rot13string(va_list mytypes, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

/* width handler */
int handle_write_char(char c, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int write_number(int is_positive, int ind, char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);
int write_num(int ind, char mybuffer[], int myflag,
	int mywidth, int myprecision,
	int mylength, char padd, char extra_c);
int write_pointer(char mybuffer[], int ind, int mylength,
	int mywidth, int myflags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char mybuffer[],
	int myflags, int mywidth, int myprecision, int mysize);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
