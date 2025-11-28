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
<<<<<<< HEAD

	c = va_arg(args, int);
=======
	
	c = (char)va_arg(args, int);
	
>>>>>>> ad28242d3334637417644e42503a91bfe77f4bd1
	_putchar(c);
	
	return (1);
}

