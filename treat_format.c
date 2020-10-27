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
char *(*get_print_func(char c))(modifier_t *, va_list)
{
	int i;
	t_print t[] = {
	    {'c', print_char},
	    {'s', print_string},
	   /**
	    *{'i', print_int},
	    *{'d', print_int},
	    *{'u', print_unsigned_int},
	    *{'o', print_octal},
	    *{'x', print_hex},
	    *{'X', print_hex},
	    *{'b', print_binary},
	    *{'S', print_big_s},
	    *{'p', print_pointer},*/
	    {'r', print_rev},
	    /**{'R', print_rot},
	    */
	    {'\0', NULL}};
	for (i = 0; t[i].f; i++)
	{
		if (t[i].f == c)
			return (t[i].func);
	}
	return (NULL);
}

/**
 * treat_format - treats every case of '%' inside format given at pos
 * @format: string to treat
 * @pos: position of '%' to treat in format (will be modified to mark
 * end of searching position)
 * @ap: va_list pointer containng data to format
 *
 * Return: result string formated
 */
char *treat_format(const char *format, unsigned int *pos, va_list ap)
{
	char *(*fun_p)(modifier_t *, va_list);
	modifier_t *modif;
	unsigned int end_pos;
	char *res_str, *aux;

	if (!format || !format[(*pos) + 1])
	{
		(*pos)++;
		return (NULL);
	}
	aux = malloc(sizeof(char) * 2);
	aux[0] = '%';
	aux[1] = '\0';
	if (format[(*pos) + 1] == '%')
	{
		(*pos) += 2;
		return (aux);
	}
	end_pos = *pos;
	modif = get_modifier(format, &end_pos);
	if (modif == NULL)
	{
		(*pos)++;
		return (aux);
	}
	fun_p = get_print_func(modif->specifier);
	if (!fun_p)
	{
		free(modif);
		(*pos)++;
		return (aux);
	}
	free(aux);
	res_str = fun_p(modif, ap);
	free(modif);
	*pos = end_pos + 1;
	return (res_str);
}
