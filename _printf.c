#include "main.h"

/**
 * _printf - replicates the behavior of printf
 * @format: string containing text and format specifiers
 * 
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
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
}
