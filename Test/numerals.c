#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: Format string.
 *
 * Return: Number of characters printed (excluding null byte).
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
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')

			{

				num_print = va_arg(args, int);

				str = malloc(12);

				if (str == NULL)
					return -1;

				len = sprintf(str, "%d", num_print);
				write(1, str, len);
				num_print += len;
				free(str);
			}

			else {
				write(1, "%", 1);
				write(1, format, 1);
				num_print += 2;
			}
		}

		else {
			write(1, format, 1);
			num_print++;
		}

		format++;
	}

	va_end(args);

	return num_print;
}

