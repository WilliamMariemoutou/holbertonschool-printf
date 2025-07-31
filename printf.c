#include "main.h"
#include <stdarg.h>  /* For handling variable arguments */
#include <unistd.h>  /* For the write() system call */

/**
 * _printf - Produces output according to a format string
 * @format: The format string containing characters and format specifiers
 *
 * Return: Number of characters printed (excluding the terminating null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;   /* To store the variable arguments */
    int i = 0;      /* Index to traverse the format string */
    int j;          /* Index for traversing strings */
    int count = 0;  /* Counter for the number of characters printed */

    /* If format is NULL, return error code */
    if (format == NULL)
        return (-1);

    /* If the format string is empty, nothing to print, return 0 */
    if (format[0] == '\0')
        return (0);

    /* Initialize the args list to start after 'format' */
    va_start(args, format);

    /* Loop through each character in the format string */
    while (format[i] != '\0')
    {
        /* Check for %c specifier (print a character) */
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            /* Get next argument as int (char promoted to int in variadic args) */
            char ch = va_arg(args, int);

            /* Write the character to stdout */
            write(1, &ch, 1);

            /* Increment character count */
            count++;

            /* Skip past the '%' and 'c' */
            i += 2;
        }
        /* Check for %s specifier (print a string) */
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            /* Get next argument as string (char pointer) */
            char *str = va_arg(args, char *);

            /* If string is NULL, print "NO STRING" instead */
            if (str == NULL)
                str = "NO STRING";

            /* Write each character of the string */
            for (j = 0; str[j] != '\0'; j++)
            {
                write(1, &str[j], 1);
                count++;
            }

            /* Skip past the '%' and 's' */
            i += 2;
        }
        /* Check for %% specifier (print a single percent sign) */
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            write(1, "%", 1);
            count++;
            i += 2;
        }
        /* Otherwise, just print the current character */
        else
        {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }

    /* Clean up the args list */
    va_end(args);

    /* Return total number of characters printed */
    return (count);
}	
