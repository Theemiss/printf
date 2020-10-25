#include "holberton.h"
#include <stdio.h>

/**
 * free_modifier - free struct modifier
 * @modif: pointer to struct modifier to free
 *
 */
void free_modifier(modifier_t *modif)
{
	free(modif->flags);
	free(modif->length);
	free(modif);
}

/**
 * get_modifier - extracts modifiers into a new struct modifier
 * @s: string to extract from
 * @pos: position to start from (will be modifed to
 * the position of last character checked)
 *
 * Return: pointer on new struct modifier or NULL if specifier not found
 */
modifier_t *get_modifier(const char *s, unsigned int *pos)
{
	modifier_t *modif;
	unsigned int i = *pos;

	if (s[i + 1] == '\0')
		return (NULL);
	modif = malloc(sizeof(modifier_t));
	if (modif == NULL)
		return (NULL);
	modif->flags = get_flags(s, &i);
	modif->width = get_width(s, &i);
	modif->precision = get_precision(s, &i);
	modif->length = get_length(s, &i);
	modif->specifier = get_specifier(s, &i);

	if (!modif->specifier)
	{
		free_modifier(modif);
		return (NULL);
	}
	//printf("flag: %s | width: %d | prec: %d | length: %s | spec: %c |\n", modif->flags, modif->width, modif->precision, modif->length, modif->specifier);
	(*pos) = i;
	return (modif);
}

/**
 * get_print_func - gets the apropriate printing function
 * for a given format-specifier
 * @c: format-specifier
 *
 * Return: pointer to a function or NULL if not found
 */
int (*get_print_func(char c))(modifier_t *, va_list)
{
	int i;
	t_print t[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_decimal},
		{'u', print_unsigned_int},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex},
		{'b', print_binary},
		{'S', print_big_s},
		{'\0', NULL}
	};

	for (i = 0; t[i].f; i++)
	{
		if (t[i].f == c)
			return (t[i].func);
	}
	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed excluding the null byte
 * used to end output to strings
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*fun_p)(modifier_t *, va_list);
	modifier_t *modif;
	unsigned int i, printed, count = 0;

	if (!format || !format[0] )
	{
		return (-1);
	}
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			modif = get_modifier(format, &i);
			if (modif == NULL)
			{
				_putchar(format[i++]);
				count++;
			}
			/**
			 * ToDo: when get_modifier() fails to allocate;
			 */
			else
			{
				fun_p = get_print_func(modif->specifier);
				printed = fun_p(modif, ap);
				count += printed;
				i++;
			}
		}
		else
		{
			_putchar(format[i++]);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
