#include "holberton.h"
#include <stdio.h>

/**
 *
 */
int buffer_print(char buffer[], unsigned int pos)
{
	write(1, buffer, pos - 1);
	return (pos);
}

/**
 * buffer_add - adds a string to buffer
 * @buffer: buffer to fill
 * @str: str to add
 * @buffer_pos: pointer to buffer first empty position
 *
 * Return: if buffer filled and emptyed return number of printed char
 * else 0
 */
int buffer_add(char buffer[], char *str, unsigned int *buffer_pos)
{
	int length, i, size = BUFFER_SIZE - 1;
	unsigned int count = 0, pos = *buffer_pos;

	for (length = 0; str[length]; length++)
		;
	while (str[i])
	{
		if (pos == size + 1)
		{
			count += buffer_print(buffer, pos);
			pos = 0;
		}
		buffer[pos++] = str[i++];
	}
	*buffer_pos = pos;
	return (count);
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
	unsigned int i = 0, buffer_pos = 0, count = 0;
	char *res_str , *aux, buffer[BUFFER_SIZE];

	if (!format || !format[0])
		return (-1);
	va_start(ap, format);
	aux = malloc(sizeof(char) * 2);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			res_str = treat_format(format, &i, ap);
			count += buffer_add(buffer, res_str, &buffer_pos);
		}
		else
		{
			aux[0] = format[i];
			aux[1] = '\0';
			count += buffer_add(buffer, aux, &buffer_pos)
			
		}
	}
	count += buffer_print(buffer, buffer_pos)
	free(aux);
	va_end(ap);
	return (count);
}
