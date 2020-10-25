#include "holberton.h"
/**
 * print_char - print a single char
 * @ap: va_list pointer
 * Return: one char count
 */
int print_char (va_list c)
{
	char ch;


	ch = (char)va_arg(c, int);

	_putchar(c);

		return (1);
}
