#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

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
 */

void _putchar(char c) /* implicit delcaration error */
{
	write(1, &c, 1);
}

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0') /* Needs to be placed in the numericals file */
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			int value = va_arg(args, int);

            /* Print the integer digit by digit */
			int divisor = 1;
			while (value / divisor > 9)
			{
				divisor *= 10;
            }
			while (divisor != 0)
			{
				_putchar('0' + value / divisor);
				value %= divisor;
				divisor /= 10;
			}

				format += 2; /* Move past '%d' */
        }
		else if (*format == '%' && *(format + 1) == 's')
		{
			char *str = va_arg(args, char *);

            /* Print each character of the string */
			while (*str != '\0')
			{
				_putchar(*str);
				str++;
            }

			format += 2; /* Move past '%s' */
        } else
		{
			_putchar(*format);
			format++;
		}
	}

	va_end(args);
	return (0); /* return could potentially be changed */
}
