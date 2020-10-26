#include "holberton.h"

/**
 * ctox - print charachter as hexadecimal
 * @c: charachter to print
 *
 */
void ctox(char c)
{
	char buffer;

	buffer = c % 16;
	c /= 16;
	c %= 16;
	if (c > 9)
		_putchar((c % 10) + 'A');
	else
		_putchar(c + '0');
	if (buffer > 9)
		_putchar((buffer % 10) + 'A');
	else
		_putchar(buffer + '0');
}

/**
 * print_big_s - print a string with non printable characters as hex
 * @modif: struct containing modifier fields
 * @ap: va_list pointer containig string to print
 *
 * Return: string lenght
 */
int print_big_s(modifier_t *modif, va_list ap)
{
	char *str, c;
	unsigned int count = 0, i;

	if (!ap || !modif || modif->specifier != 'S')
		return (0);

	str = va_arg(ap, char *);
	for (i = 0; str[i]; i++)
	{
		c = str[i];
		if ((c > 0 && c <= 32) || c >= 127)
		{
			_putchar(92);
			_putchar('x');
			ctox(c);
			count += 4;
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
