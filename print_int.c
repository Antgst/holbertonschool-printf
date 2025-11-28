#include "main.h"

/**
 * print_int - Affiche un entier signé
 * @args: va_list contenant l'entier à afficher
 *
 * Return: Nombre de caractères imprimés
 */
int print_int(va_list args)
{
	int count = 0;
	int integer;
	unsigned int number;

	integer = va_arg(args, int);

	if (integer < 0)
	{
		_putchar('-');
		count++;
		number = -integer;
	}
	else
	{
		number = integer;
	}

	if (integer == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count += print_int_recursive(number);
	}
	return (count);
}

/** 
 * print_int_recursive - Print an unsigned integer recursively
 * @n: the unsigned integer to print
 *
 * Return: The number of characters printed
*/

int print_int_recursive(unsigned int number)
{
	int count;
	
	if (number == 0)
		return (0);
	else
	{
		count = print_int_recursive(number / 10);
		_putchar((number % 10) + '0');
		return (count + 1);
	}
}