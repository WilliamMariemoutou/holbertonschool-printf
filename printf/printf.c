#include "main.h"       /* Include custom header file */
#include <stdarg.h>     /* For handling variable argument list macros */
#include <unistd.h>     /* For write function to output to stdout */

/**
 * _printf - Produces output according to a format
 * @format: The format string (contains text and format specifiers)
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;       /* Declare a variable to hold the argument list */
    int i = 0;          /* Index to traverse the format string */
    int count = 0;      /* Count of characters printed */
	int j = 0;

    if (format == NULL) /* Check for NULL format string */
        return (-1);    /* Return -1 to indicate error */

    va_start(args, format); /* Initialize args to retrieve arguments after 'format' */

    while (format[i] != '\0') /* Loop until end of format string */
    {
        /* Check for %c specifier (character) */
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            char ch = va_arg(args, int);   /* Get the next argument as an int (char is promoted to int) */
            write(1, &ch, 1);              /* Write the character to stdout */
            count++;                       /* Increment count for one character printed */
            i += 2;                        /* Skip both '%' and 'c' */
        }

        /* Check for %s specifier (string) */
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            char *str = va_arg(args, char *); /* Get next argument as a string (char pointer) */
            if (str == NULL)                  /* If the string is NULL */
                str = "(null)";               /* Replace with default string "(null)" */

            /* Loop through each character in the string */
            for (j = 0; str[j] != '\0'; j++)
            {
                write(1, &str[j], 1); /* Write each character to stdout */
                count++;              /* Increment count for each character printed */
            }
            i += 2; /* Skip both '%' and 's' */
        }

        /* Check for %% specifier (literal percent sign) */
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            write(1, "%", 1); /* Write a literal '%' to stdout */
            count++;          /* Increment count */
            i += 2;           /* Skip both '%' characters */
        }

        /* Regular character, just print it */
        else
        {
            write(1, &format[i], 1); /* Write current character to stdout */
            count++;                 /* Increment count */
            i++;                     /* Move to next character */
        }
    }

    va_end(args); /* Clean up the variable argument list */
    return (count); /* Return total number of characters printed */
}
