#include"holberton.h"

/**
 * print_string - print a string
 * @modif: struct containing modifier fields
 * @ap: va_list pointer containing a string
 *
 * Return: string lenght
 */
char *print_string(modifier_t *modif, va_list ap)
{
	char *str;

	if (!ap || !modif)
		return (0);
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	return (str);
}
