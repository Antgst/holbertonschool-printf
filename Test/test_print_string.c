#include "main.h"

/**
 * print_string - Affiche une chaîne de caractères
 * @args: va_list contenant la chaîne à afficher
 *
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}

	return (count);
}
