#include "holberton.h"
/**
 * print_char - print a single char
 * @ap: va_list pointer
 * Return: one char count
 */
int print_char (va_list ap)
{
	char c;


	c = (char)va_arg(ap, int);

	_putchar(c);

		return (1);
}
