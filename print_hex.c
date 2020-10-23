#include "holberton.h"

/**
 * print_hex - print usigned decimal as hexadecimal
 * @format_spec: format_specifier should be "%x" for lowercase or
 * "%X" for uppercase
 * @ap: va_list pointer containig unsigned int to print
 *
 * Return: number of printed characters
 */

int print_hex(char *format_spec, va_list ap)
{
	unsigned int count = 0, n, aux;
	int i = 0;
	char buffer[8], _case;

	if (!ap || !format_spec)
		return (0);
	n = va_arg(ap, unsigned int);
	_case = format_spec[1] == 'x' ? 'a' : 'A';
	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (n)
		{
			aux = n % 16;
			if (aux > 9)
				buffer[i++] = (aux % 10) + _case;
			else
				buffer[i++] = aux + '0';
			n = n / 16;
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
