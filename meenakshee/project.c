#include "main.h"
#include <stdargs.h>
#include <unistd.h>
/**
 * _printf - produces the output according to a format
 * @format: character string
 *
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	va_list(args);
	va_start(args, format);
	int i = 0;
	int count = 0;

	while (format[i] != '\0')
	{

		write(1, &format[i], 1);
		count++;
		i++;
	}


	va_end(args);
	return (count);
}
