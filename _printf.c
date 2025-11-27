#include "main.h"

/**
<<<<<<< HEAD
 * get_print_func - selects the correct function to handle a specifier
 * @c: the format specifier character (c, s, d, i, b...)
 *
 * Return: pointer to the corresponding function, or NULL if not found
 */
=======
 
get_print_func - selects the correct function to handle a specifier
@c: the format specifier character (c, s, d, i, b...)*
Return: pointer to the corresponding function, or NULL if not found*/
>>>>>>> main

int _printf(const char *format, ... )
{
    va_list args;
    int i = 0, j, count = 0;

    spec_t types[] =
    {
<<<<<<< HEAD
        {'c', print_char},
        {'s', print_string},
        {'d', print_int},
        {'%', print_percent},
		{'i', print_int},
=======
        {'c', print_char}, 
        {'s', print_string},
        {'d', print_int},
        {'%', print_percent},
        {'i', print_int},
>>>>>>> main
        {'\0', NULL}
    };

    if (!format)
        return (-1);

<<<<<<< HEAD
    va_start(args, format)








}
=======
    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if(format[i] == '%')
            i++;
            
            /** 
             * pour suite faire la fonction qui appelle chaque caractère (entre i++ et else)
            */


        else
            _putchar(format[i]);
            count++;
    }
    va_end(args);
    return (count);

}
>>>>>>> main
