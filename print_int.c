#include "holberton.h"
/**
 * print_int - print integer
 * @ap:va_list pointer for integer handle %i
 * @modif:struct modifier containig modifier fields
 * Return:int length
 */
char *print_int(modifier_t *modif, va_list ap)
{
	unsigned int n;
	int i = 0, j = 0;
	char buf[10], *str;

	if (!ap || !modif )
		return (NULL);
	n = va_arg(ap, int);
	if (n == 0)
	{
		j = 1;
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
	}
	else
	{
		while (n)
		{
			buf[i++] = (n % 10) + '0';
			n = n / 10;
		}
		str = malloc(sizeof(char) * i);
		i--;
		while (i >= 0)
			str[j++] = buf[i--];
	}
	str[j] = '\0';
	return (str);
}
