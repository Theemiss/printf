#include "holberton.h"
/**
 * format_specifiers - check the format
 * @format: type of format
 * 
 * Return : function to be printed
 */
int (*format_specifiers(const char *format))(va_list)	
{
	unsigned int i = 0;
t_print t[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_decimal},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"b", print_binary}
		{NULL, NULL}
	};
while (t[i].f != NULL)
{
	if (*(t[j].f) == format[i])
	{
		break;
	}
	return (t[i].print_T(va_list);

}