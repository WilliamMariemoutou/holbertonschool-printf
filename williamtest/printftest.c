#include "main.h"
#include <stdarg.h> // gives access to va_list, va_start, va_arg, va_end
#include <unistd.h>


/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...) // prototype given
{
    va_list args; // skeleton - for extra arguments

    va_start(args, format); // tells the compiler where the argument starts after format

    int i = 0;
int count = 0;

while (format[i] != '\0')

{
write(1, &format[i], 1);
count++;
i++;
}

    va_end(args); // required to clean up
  return (count);
}

