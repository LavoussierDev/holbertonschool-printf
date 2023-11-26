#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 * @...: Variable number of arguments corresponding to the specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */


int _printf(const char *format, ...)
{
	int num_print = 0;
	int len;
	char *str;

	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		/* Move to char after % */

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

				/*
				 * Convert int to string, write string to stdout,
				 * update the total of char printed
				 * free string
				 */

				len = sprintf(str, "%d", num_print);

				write(1, str, len);
				num_print += len;

				free(str);
			}

			else {
				/**
				 *  Write % char to stdout, write the char after it,
				 *  and update the total char printed
				 */

				write(1, "%", 1);
				write(1, format, 1);
				num_print += 2;
			}
		}

		else {

			/* Write char to stdout and update the total of char printed */

			write(1, format, 1);
			num_print++;
		}

		/* Move to the next char in the string */

		format++;
	}

	va_end(args);
	return num_print;
}
