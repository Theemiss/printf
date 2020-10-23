#include "holberton.h"

/**
 * print_char - print a single char
 * @ap: va_list pointer
 * Return: one char count
 */
int print_char (va_list ap)
{
	char c;


	c = va_arg(ap, char);

	_putchar(c);

		return (1);
}
