#include "main.h"

/**
 * get_print_func - selects the correct function to handle a specifier
 * @c: the format specifier character (c, s, d, i, b...)
 *
 * Return: pointer to the corresponding function, or NULL if not found
 */

int get_print_func(char c)(va_list)
{
    print_t types[] =
    {
        {'c', print_char},
        {'s', print_string},
        {'d', print_int},
		{'i', print_int},
        {'\0', NULL}
    };
    int i = 0;

    while (types[i].spec != '\0')
    {
        if (types[i].spec == c)
        {
            return (types[i].f);
        }
        i++;
    }
    return (NULL);
}
