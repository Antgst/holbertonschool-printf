#include "main.h"

/**
<<<<<<< HEAD
 * _printf - replicates the behavior of printf
 * @format: string containing text and format specifiers
 * 
 *Return: pointer to the corresponding function, or NULL if not found
=======
 * get_print_func - selects the correct function to handle a specifier
 * @c: the format specifier character (c, s, d, i, b...)
 *
 * Return: pointer to the corresponding function, or NULL if not found
>>>>>>> 4908b9c013dfd82f792da9db5770d66143224e1e
 */

int _printf(const char *format, ... )
{
    va_list args;
    int i = 0, j, count = 0;

    spec_t types[] =
    {
        {'c', print_char},
        {'s', print_string},
        {'d', print_int},
        {'%', print_percent},
		{'i', print_int},
        {'\0', NULL}
    };

    if (!format)
        return (-1);

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if(format[i] == '%')
        {    
            i++;
            for(j = 0; types[j].spec != '\0'; j++)
            {
                if(types[j].spec == format[i])
                {
                    count += types[j].f(args);
                    break;
                }
            }
            if (types[j].spec == '\0')
                count += _putchar('%') + _putchar(format[i]);
        }
        else
            count += _putchar(format[i]);
    }
    va_end(args);
    return (count);
<<<<<<< HEAD
=======

>>>>>>> 4908b9c013dfd82f792da9db5770d66143224e1e
}
