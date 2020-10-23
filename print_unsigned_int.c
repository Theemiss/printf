#include "holberton.h"

/**
 * print_unsigned_int - print usigned integer for 'u' conversion specifier
 * @format_spec: format_specifier should be "%u"
 * @ap: va_list pointer containig unsigned int to print
 *
 * Return: number of printed characters
 */

int print_unsigned_int(char *format_spec, va_list ap)
{
	unsigned int count = 0, n;
	int i = 0;
	char buffer[10];

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
			buffer[i++] = (n % 10) + '0';
			n = n / 10;
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
