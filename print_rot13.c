#include "holberton.h"

/**
 * print_rot - encodes a string into rot13
 * @ap: arg to display handle %R
 * Return: count of string
 */
char print_rot(va_list R)
{
	char *str;
	int count = 0;
	unsigned int i, j;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	str = va_arg(R, char *);

	for (i = 0; *(str + i); i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (a[j] == *(str + i))
			{
				*(str + i) = b[j];
				count++;
				break;
			}
		}
	if (!a[j])
		{
			_putchar(str[i]);
			count++;
		}
	}
	return(count);
}