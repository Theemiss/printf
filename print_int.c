#include "holberton.h"
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
int int_len(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
char *ito( int n)
{
	int len = 0, i = 0;
	char *str;

	len = int_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (n / 10)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[i] = (n % 10) + '0';
	array_rev(str, len);
	str[i + 1] = '\0';
	return (str);
}
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
