#include"holberton.h"

/**
 * print_string - print a string
 * @ap:va_list pointer containing a string
 * Return:string lenght
 */
int print_string(va_list ap)
{
	char *str;
	unsigned int count;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";

	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
return (count);

}
