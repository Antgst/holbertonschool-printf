#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments from which to get the character
 *
 * Return: number of characters printed (1)
 */

int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}
