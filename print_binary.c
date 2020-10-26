#include "holberton.h"

/**
 * print_binary - print unsigned int as a binary
 * @modif: struct containing modifier fields
 * @ap: va_list pointer containing unsigned int to convert and print
 *
 * Return: number of printed charachters
 */

int print_binary(modifier_t *modif, va_list ap)
{
	unsigned int count = 0, n;
	int i = -1;
	char binary[32];

	if (!ap || !modif || modif->specifier != 'b')
		return (0);
	n = va_arg(ap, unsigned int);
	while (n)
	{
		i++;
		binary[i] = '0' + (n % 2);
		n = n / 2;
	}
	while (i >= 0)
	{
		_putchar(binary[i--]);
		count++;
	}
	return (count);
}
