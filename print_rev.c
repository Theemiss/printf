#include "holberton.h"
/**
 * print_rev - print a string in reverse
 * @ap:handle %r
 * @modif :struct modifier containig modifier fields
 * Return: lenght
 */
int print_rev(modifier_t *modif, va_list ap)
{
	char *str;
	int i, count = 0;

	if (!ap || !modif)
		return (0);

	str = va_arg(ap, char *);
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
