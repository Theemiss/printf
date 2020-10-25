#include "holberton.h"
/**
 * print_rev - print a string in reverse 
 * @r:handle %r
 * Return: lenght
 */
int print_rev(va_list r)
{
	char *str;
	int i, count = 0;

	str = va_arg(r, char *);
	if (str == NULL)
			str = "(null)";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
