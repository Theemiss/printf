#ifndef _FUNCTION_PRINTF_H_
#define _FUNCTION_PRINTF_H_
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int print_binary(char *, va_list);
int print_unsigned_int(char *, va_list);
int print_octal(char *, va_list);
int print_hex(char *, va_list);
int print_char(va_list ap);
int print_int(va_list ap);

#endif
