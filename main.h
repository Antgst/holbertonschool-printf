#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
 * struct print_s - Struct for format specifiers
 * @spec: the format specifier character (e.g. 'c', 's', 'd')
 * @f: pointer to the function that handles this specifier
 */

typedef struct print_s
{
	char spec;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int get_print_func(va_list args);

#endif
