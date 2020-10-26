#include "holberton.h"
/**
 * print_char - print a single char
 * @ap: va_list pointer containg a char
 * @modif: struct modifier containig modifier fields
 * Return: one char count
 */
char print_char (modifier_t *modif, va_list ap)
{
	char ch;

	if (!ap || !modif)
		return (0);

	ch = (char)va_arg(ap, int);

	return (ch);
}
