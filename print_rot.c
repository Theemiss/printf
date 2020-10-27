#include "holberton.h"
#include "holberton.h"
/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}
/**
 * rot13 - encodes a string into rot13
 * @str: string to encode
 *
 * Return: address of s
 */
char *rot13(char *str)
{
	int i;
	int j;
	int l = _strlen(str);
	char *s;
	char *alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *shift = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	s = malloc(l + 1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alph[j])
			{
				s[i] = shift[j];
				break;
			}
		}
		if (j == 52)
			s[i] = str[i];
	}
	return (s);
}
/**
 * print_rot - encodes a string into rot13
 * @ap: arg to display handle %R
* @modif:struct modifier containig modifier fields
 * Return: count of string
 */
char *print_rot(modifier_t *modif, va_list ap)
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
	res = rot13(str);
	return (res);
}
