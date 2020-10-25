#include"holberton.h"

/**
 * print_string - print a string
 * @ap:va_list pointer containing a string
 * Return:string lenght
 */
int print_string(va_list s)
{
	char *str;
	unsigned int count = 0, i;

	str = va_arg(s, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		count++;
	}
return (count);

}
