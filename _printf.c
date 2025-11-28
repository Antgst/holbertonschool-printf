#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing conversion specifiers
 *
 * Return: number of chars printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j, count = 0;

    spec_t types[] = {
        {'c', print_char},
        {'s', print_string},
        {'d', print_int},
        {'i', print_int},
        {'%', print_percent},
        {'\0', NULL}
    };

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;

            /* '%' suivi de rien → erreur */
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
            }

            /* On cherche le bon specifier */
            for (j = 0; types[j].c != '\0'; j++)
            {
                if (types[j].c == format[i])
                {
                    count += types[j].f(args);
                    break;
                }
            }

            /* Specifier inconnu → impression brute */
            if (types[j].c == '\0')
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }

        i++;
    }

    va_end(args);
    return (count);
}
