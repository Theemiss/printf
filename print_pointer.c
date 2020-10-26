#include "holberton.h"

/**
 * print_pointer - print pointer as hexadecimal
 * @modif: struct containing modifier fields
 * @ap: va_list pointer containing pointer to print
 *
 * Return: number of printed characters
 */
int print_pointer(modifier_t *modif, va_list ap)
{
	long int p, aux;
	char buffer[1024];
	int i = 0, count = 0;

	if (!modif || !ap || modif->specifier != 'p')
		return (0);
	p = va_arg(ap, long int);
	_putchar('0');
	_putchar('x');
	count += 2;
	if (p == 0)
	{
		_putchar('0');
		return (count + 1);
	}
	while (p)
	{
		aux = p % 16;
		if (aux > 9)
			buffer[i++] = (aux % 10) + 'a';
		else
			buffer[i++] = aux + '0';
		p /= 16;
	}
	i--;
	while (i >= 0)
	{
		_putchar(buffer[i--]);
		count++;
	}
	return (count);
}
