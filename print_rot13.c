#include "holberton.h"
/**
 * 
 * 
 * 
 * 
 */
char *rot13(char *s)
{
	int i, j;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; *(s + i); i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (a[j] == *(s + i))
			{
				*(s + i) = b[j];
				break;
			}
		}
	}
	return (s);
}
/**
 * print_rot - encodes a string into rot13
 * @ap: arg to display handle %R
 * Return: count of string
 */
int print_rot(modifier_t *modif, va_list ap)
{	char *str, *s;
	unsigned int count = 0, i;

if (!ap || !modif)
		return (0);

	str = va_arg(ap, char *);
	s = rot13(str);
	for (i = 0; s[i]; i++)
	{
		_putchar(s[i]);
		count++;
	}
return (count);
}