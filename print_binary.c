#include "holberton.h"

/**
 * print_binary - print unsigned int as a binary
 * @format_spec: format_specifier should be "%b"
 * @ap: va_list pointer containing unsigned int to convert and print
 *
 * Return: number of printed charachters
 */

int print_binary(char *format_spec, va_list ap)
{
	unsigned int count = 0, n;

	if (!ap || !format_spec)
		return (0);
	n = va_arg(ap, unsigned int);
	while (n)
	{
		_putchar((n % 2) + '0');
		n = n / 2;
		count++;
	}
	return (count);
}
