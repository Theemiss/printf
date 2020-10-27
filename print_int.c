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
	char number;
	char *res, *str;

	if (!ap || !modif)
		return (0);
	number = va_arg(ap, int);
	str =  ito(number);
	if (str == NULL)
	{
		res = malloc(sizeof(char) * 7);
		res = _strcpy(res, "(null)");
		return (res);
	}
	if (str[0] == '\0')
		return (NULL);
	res = malloc(_strlen(str) + 1);
	if (!res)
		return (NULL);
	res = _strcpy(res, str);

	return (res);
}
