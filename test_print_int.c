#include "main.h"

/**
 * print_number - prints a long integer using _putchar
 * @n: number to print (assumed non-negative)
 *
 * Return: number of characters printed
 */
static int print_number(long n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_int - prints an integer (for %d and %i)
 * @args: list of arguments from which to get the integer
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	long num = n;
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	count += print_number(num);

	return (count);
}
