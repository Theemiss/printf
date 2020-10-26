#include"holberton.h"

/**
 * print_string - print a string
 * @modif: struct containing modifier fields
 * @ap: va_list pointer containing a string
 *
 * Return: string lenght
 */
int print_string(modifier_t *modif, va_list ap)
{
	char *str;
	unsigned int count = 0, i;

	if (!ap || !modif)
		return (0);
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
