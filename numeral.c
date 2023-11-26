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
	// Initialize variables

	int num_print = 0;
	int len;
	char *str;


	va_list args;
	va_start(args, format);


	// Iterate through the format string

	while (*format != '\0')
	{
		// Check for conversion specifier (%)

		if (*format == '%')

		{
			format++; // Move to the next character after %

			// Check for 'd' or 'i' conversion specifier

			if (*format == 'd' || *format == 'i')

			{
				// Get the integer argument

				num_print = va_arg(args, int);

				// Allocate memory for the string representation of the integer

				str = malloc(12);

				// Check for memory allocation failure

				if (str == NULL)
				{
					return -1;
				}

				// Convert integer to string, write to stdout, and update total printed

				len = sprintf(str, "%d", num_print);
				write(1, str, len);
				num_print += len;

				// Free the allocated memory

				free(str);
			}

			else
			{
				// Write '%' and the next character to stdout and update total printed

				write(1, "%", 1);
				write(1, format, 1);
				num_print += 2;
			}
		}

		else
		{
			// Write the character to stdout and update total printed

			write(1, format, 1);
			num_print++;
		}

		// Move to the next character in the format string

		format++;
	}

	// Clean up and return the total number of characters printed

	va_end(args);
	return num_print;
}

