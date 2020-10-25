#include "holberton.h"

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
modifier_t *get_modifier(char *s, unsigned int *pos)
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
	(*pos) = i;
	return (modif);
}

/**
 *
 */


/**
 *
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*fun_p)(modifier_t, va_list);
	modifier_t *modif;
	unsigned int i,count =0;

	if (format == '\0')
	{
		return(-1);
	}
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			modif = get_modifier(format, &i);
			if (modif == NULL)
				_putchar(format[i]);
			else
			{
				fun_p == get_print_func(modif->specifier);
				count = count + fun_p(modif, ap);
			}
		}		
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(ap);
	return(count);
}
