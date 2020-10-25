#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * format_specifiers - check the format
 * @format: type of format
 * 
 * Return : function to be printed
 */
int (*format_specifiers(const char *format, int i))(va_list)
{
	int j;
t_print t[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_decimal},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"b", print_binary},
		{NULL, NULL}
	
};
for (j = 0; t[j].f; j++)
{
if (t[j].f[0] == format[i])
	return (t[j].func);
}
return (0);
}
