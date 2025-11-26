#include "main.h"

/**
 * get_print_func - Sélectionne la fonction associée à un spécificateur
 * @s: caractère du format (c, s, d, i, b...)
 *
 * Return: Pointeur vers la fonction correspondante ou NULL
 */
int (*get_print_func(char s))(va_list)
{
	print_t types[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{0, NULL}
	};

	int i = 0;

	while (types[i].t != 0)
	{
		if (types[i].t == s)
			return (types[i].f);
		i++;
	}

	return (NULL);
}
