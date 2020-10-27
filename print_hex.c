#include "holberton.h"

/**
 * print_hex - print usigned decimal as hexadecimal
 * @modif: struct modifier containig modifier fields
 * @ap: va_list pointer containig unsigned int to print
 *
 * Return: number of printed characters
 */

char *print_hex(modifier_t *modif, va_list ap)
{
	unsigned int n, aux;
	int i = 0, j = 0;
	char buffer[8], _case, *res_str;

	if (!ap || !modif)
		return (0);
	n = va_arg(ap, unsigned int);
	_case = modif->specifier == 'x' ? 'a' : 'A';
	if (n == 0)
	{
		j = 1;
		res_str = malloc(sizeof(char) * 2);
		res_str[0] = '0';
	}
	else
	{
		while (n)
		{
			aux = n % 16;
			if (aux > 9)
				buffer[i++] = (aux % 10) + _case;
			else
				buffer[i++] = aux + '0';
			n = n / 16;
		}
		res_str = malloc(sizeof(char) * i);
		i--;
		while (i >= 0)
			res_str[j++] = buffer[i--];
	}
	res_str[j] = '\0';
	return (res_str);
}
