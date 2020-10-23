#include "holberton.h"

/**
 *
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
