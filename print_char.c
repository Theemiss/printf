#include "holberton.h"
/**
 * print_char - print a single char
 * @ap: va_list pointer
 * Return: one char count
 */
int print_char (modifier_t *modif, va_list ap)
{
	char ch, _case;
	if (!ap || !modif)
		return (0);

	ch = (char)va_arg(ap, int);
		_case = modif->specifier == 'c';
		_putchar(ch);

		return (1);
}
