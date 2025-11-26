#include "main.h"

/**
 * print_int - Affiche un entier signé
 * @args: va_list contenant l'entier à afficher
 *
 * Return: Nombre de caractères imprimés
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	/* Si négatif, afficher le '-' */
	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	/* Appel récursif pour imprimer chiffre par chiffre */
	if (num / 10)
		count += print_number(num / 10);

	/* Afficher le dernier chiffre */
	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * print_number - Fonction interne récursive pour imprimer un entier positif
 * @num: nombre positif à afficher
 *
 * Return: Nombre de caractères imprimés
 */
int print_number(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}
