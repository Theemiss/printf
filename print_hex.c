#include "holberton.h"

/**
 * print_hex - print usigned decimal as hexadecimal
 * @modif: struct modifier containig modifier fields
 * @ap: va_list pointer containig unsigned int to print
 *
 * Return: number of printed characters
 */

int print_hex(modifier_t *modif, va_list ap)
{
	unsigned int count = 0, n, aux;
	int i = 0;
	char buffer[8], _case;

	if (!ap || !modif)
		return (0);
	n = va_arg(ap, unsigned int);
	_case = modif->specifier == 'x' ? 'a' : 'A';
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
