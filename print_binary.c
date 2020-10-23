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
	int i = 0;
	char binary[32];

	if (!ap || !format_spec)
		return (0);
	n = va_arg(ap, unsigned int);
	while (n)
	{
		binary[i++] = '0' + (n % 2);
		n = n / 2;
	}
	while (i >= 0)
	{
		_putchar(binary[i--]);
		count++;
	}
	return (count);
}
