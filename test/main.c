#include <limits.h>
#include <stdio.h>
#include "holberton.h"




/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    unsigned int ui;
    void *addr;

    _printf("Unknown:[%R]\n", "encrypted message");
    len = _printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    _printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    _printf("%%\n");
_printf("%");
_printf("%%r\n");
_printf("hello%%\n");
_printf("minehello%");
_printf("hello%r\n");
_printf("mineUnknown:[%r]\n");
_printf("mineCharacter:[%c]\n", 'H');
_printf("Let's try to printf a simple sentence.\n");
_printf("String:[%s]\n", "I am a string !");
    return (0);
}
