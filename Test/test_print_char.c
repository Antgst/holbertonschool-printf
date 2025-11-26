#include "main.h"

/**
 * print_char - Affiche un caractère
 * @args: va_list contenant le caractère à afficher
 *
 * Return: Nombre de caractères imprimés (toujours 1)
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}
