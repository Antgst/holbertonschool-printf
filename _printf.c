#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string with format specifiers
 * 
 * Return: number of characters printed (excluding the null byte)
 * or -1 if format is NULL or an error occurs
 */

 int _printf(const char *format, ...)
 {
    va_list args;
    int i = 0;
    int count = 0;
    int (*f)(va_list);

    if (format == NULL)
    return (-1);

va_start(args, format);

while (format[i] != '\0')
{
    if (format[i] != '%')
    {
        _putchar(format[i]);
        count++;
    }
    else
    {
        i++;
        
        if (format[i] == '\0')
        {
            va_end(args);
            return (-1);
        }

        if (format[i] == '%')
        {
            _putchar('%');
            count++;
        }
        else
        {
            f = get_print_func(va_list args);
            if (f != NULL)
            {
                count += f(args);
            }
            else
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
    }
    i++;
}

va_end(args);
return (count);
}
