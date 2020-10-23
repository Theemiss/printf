#include "holberton.h"

/**
 * print_octal - print usigned decimal as octal
 * @format_spec: format_specifier should be "%o"
 * @ap: va_list pointer containig unsigned int to print
 *
 * Return: number of printed characters
 */

int print_octal(char *format_spec, va_list ap)
{
	unsigned int count = 0, n;
	int i = 0;
	char buffer[11];

	if (!ap || !format_spec)
		return (0);
	n = va_arg(ap, unsigned int);
	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (n)
		{
			buffer[i++] = (n % 8) + '0';
			n = n / 8;
		}
		i--;
		while (i >= 0)
		{
			_putchar(buffer[i--]);
			count++;
		}
	}
	return (count);
}
