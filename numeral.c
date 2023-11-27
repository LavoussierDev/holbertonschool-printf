#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int num_print = 0;
	int len;
	char *str;

	va_start(args, format);

	/* Initialize variables */



	while (*format != '\0')
	{
		/* Check for % and move to the char after it */

		if (*format == '%')

		{
			format++;


			if (*format == 'd' || *format == 'i')

			{

				/* get int argument, allocate memory */

				num_print = va_arg(args, int);

				str = malloc(12);

				/* Check for memory allocation failure */

				if (str == NULL)
				{
					return -1;
				}

				/* Convert integer to string, write to stdout, and update total printed */
				/* free alllocated memory */

				len = sprintf(str, "%d", num_print);
				write(1, str, len);
				num_print += len;

				free(str);
			}

			else
			{
				/*
				 * Write '%' and the next character to stdout
				 *  and update total printed
				 */

				write(1, "%", 1);
				write(1, format, 1);
				num_print += 2;
			}
		}

		else
		{
			/* Write the character to stdout and update total printed */

			write(1, format, 1);
			num_print++;
		}

		/* Move to the next char in the string */

		format++;
	}

	va_end(args);
	return num_print;
}

