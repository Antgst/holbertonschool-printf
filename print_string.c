#include "main.h"

/**
* print_string - prints a string
* @args: list of arguments from which to get the string
*
* Return: number of characters printed
*/

int print_string(va_list args)
{
	char *str;
	int count = 0;
	int i = 0;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		count++;
		i++;
	}

return (count);

}
