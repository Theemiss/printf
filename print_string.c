#include"holberton.h"
/**
 * 
 * 
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * print_string - print a string
 * @modif: struct containing modifier fields
 * @ap: va_list pointer containing a string
 *
 * Return: return pointer of the beginning of string
 */
char *print_string(modifier_t *modif, va_list ap)
{
	char *str;
	char *res;
	if (!ap || !modif)
		return (0);
	str = va_arg(ap, char *);
	if (!str)
		return (NULL);
	res = malloc(_strlen(str) + 1);
	if (!res)
		return (NULL);
	res = _strcpy(res, str);

	return (res);
}
