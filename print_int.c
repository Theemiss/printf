#include "holberton.h"
/**
 * print_int - print integer
 * @ap:va_list pointer for integer handle %i
 * @modif:struct modifier containig modifier fields
 * Return:int length
 */
char *print_int(modifier_t *modif, va_list ap)
{
		 int n;
	int i, j = 0;
	char buffer[10], *res_str;

	if (!ap && !modif )
		return (NULL);
	n = va_arg(ap, unsigned int);
	if (n == 0)
	{
		j = 1;
		res_str = malloc(sizeof(char) * 2);
		res_str[0] = '0';
	}
	else if (n < 0)
	{
		i = 1;
		n *= -1;
			while (n)
		{
			buffer[i++] = (n % 10) + '0';
			n = n / 10;
		}
		res_str = malloc(sizeof(char) * i);
		i--;
		res_str[0] = '-';
		j = 1;
		while (i >= 0)
			res_str[j++] = buffer[i--];
	}
	else
	{
		i = 0;
		while (n)
		{
			buffer[i++] = (n % 10) + '0';
			n = n / 10;
		}
		res_str = malloc(sizeof(char) * i);
		i--;
		while (i >= 0)
			res_str[j++] = buffer[i--];
	}
	res_str[j] = '\0';
	return (res_str);
}
