#include "holberton.h"

/**
 * print_int - print integer
 * @ap:va_list pointer for integer handle %i
 * @modif:struct modifier containig modifier fields
 * Return:int length
 */
char *print_int(modifier_t *modif, va_list ap)
{
	unsigned int x;
	int i = 0, j = 0, n;
	char buffer[10], *res_str;

	if (!ap && !modif)
		return (NULL);
	n = va_arg(ap, int);
	if (n == 0)
	{
		j = 1;
		res_str = malloc(sizeof(char) * 2);
		res_str[0] = '0';
	}
	else
	{
		if (n < 0)
			x = -n;
		else
			x = n;
		while (x)
		{
			buffer[i++] = (x % 10) + '0';
			x = x / 10;
		}
		if (n < 0)
			buffer[i++] = '-';
		res_str = malloc(sizeof(char) * i);
		i--;
		while (i >= 0)
			res_str[j++] = buffer[i--];
	}
	res_str[j] = '\0';
	return (res_str);
}
