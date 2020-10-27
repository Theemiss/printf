#include "holberton.h"
char *reverse (char *s)
{
	int count, end, begin;
	char *r = malloc (_strlen(s) * sizeof(char) + 1);
	while (s[count] != '\0')
      count++;

   end = count - 1;

   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }

   r[begin] = '\0';
	return(r);
}
/**
 * print_rev - print a string in reverse
 * @ap:handle %r
 * @modif :struct modifier containig modifier fields
 * Return: lenght
 */
char *print_rev(modifier_t *modif, va_list ap)
{
			char *str, *res;
	if (!ap || !modif)
		return (0);
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		res = malloc(sizeof(char) * 7);
		res = _strcpy(res, "(null)");
		return (res);
	}
	if (str[0] == '\0')
		return (NULL);
	malloc(sizeof(char) * _strlen(str));
	res = reverse(str);
	return (res);
}
