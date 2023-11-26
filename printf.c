#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints characters, converts format specifier,
 * numbers, special characters, essentially it's a clone
 * to the printf function in the standard library
 *
 * _putchar - outputs a character to the standard output
 *
 * @format: pointer to a string, contains format specifiers,
 * allows us to print said character
 *
 * @c: input of given character
 *
 */

void _putchar(char c) /* outputs a chartacter, word or an intenger to a stram */
{
	write(1, &c, 1);
}

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;
	va_start(arg, format);

	/* keeps track of the number of characters printed */

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 'c')
		{
            /* Handle %c - print a character */
			char ch = (char)va_arg(arg, int);
			write(1, &ch, 1);
			count++;
			format += 2;
			/* Move past '%c' */
		}
		else if (*format == '%' && *(format + 1) == 's')
		{
			/* Handle %s - print a string */
			char *str = va_arg(arg, char *);
			while (*str != '\0')
			{
				write(1, str, 1);
				str++;
				count++;
			}
			format += 2; /* Move past '%s' */
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			/* Handle %% - print a percent sign */
			write(1, "%", 1);
			count++;
			format += 2; /* Move past '%%' */
		}
		else
		{
			/* Print ordinary characters */
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(arg);

	return (count);
}
