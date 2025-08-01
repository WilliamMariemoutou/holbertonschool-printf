#include "main.h"              /* Include custom header for function declaration */
#include <stdarg.h>            /* For va_list, va_start, va_arg, va_end */
#include <unistd.h>            /* For the write system call */

/**
 * _printf - Custom printf function that mimics printf
 * @format: The format string to parse and print
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;              /* Declare variable to access variadic arguments */
	int i = 0;                 /* Index to iterate through the format string */
	int j;                     /* Index used for printing strings */
	int count = 0;             /* Counter to keep track of characters printed */

	if (format == NULL || format[0] == '\0')  /* Check for NULL or empty format */
		return (-1);            /* Return error if format is invalid */

	va_start(args, format);    /* Initialize args to start reading after 'format' */

	while (format[i] != '\0')  /* Loop through each character in format string */
	{
		if (format[i] == '%' && format[i + 1] == 'c')  /* Handle %c (char) */
		{
			char ch = va_arg(args, int);  /* Get character argument */
			write(1, &ch, 1);              /* Print character */
			count++;                       /* Increase count */
			i += 2;                        /* Skip % and format character */
		}
		else if (format[i] == '%' && format[i + 1] == 's')  /* Handle %s (string) */
		{
			char *str = va_arg(args, char *);  /* Get string argument */

			if (str == NULL)                   /* If string is NULL */
				str = "(null)";               /* Print "(null)" instead */

			for (j = 0; str[j] != '\0'; j++)   /* Loop through string */
			{
				write(1, &str[j], 1);         /* Print each character */
				count++;                      /* Count each character */
			}
			i += 2;                            /* Skip % and format character */
		}
		else if (format[i] == '%' &&
			(format[i + 1] == 'd' || format[i + 1] == 'i'))  /* Handle %d or %i */
		{
			int n = va_arg(args, int);        /* Get integer argument */
			char buf[20];                     /* Buffer to hold digits */
			int idx = 0;                      /* Index for buf array */

			if (n < 0)                        /* Handle negative numbers */
			{
				write(1, "-", 1);             /* Print negative sign */
				count++;                      /* Count the '-' */
				n = -n;                       /* Make number positive */
			}

			if (n == 0)                       /* Special case: 0 */
			{
				write(1, "0", 1);             /* Print 0 */
				count++;                      /* Count the digit */
			}
			else
			{
				while (n > 0)                 /* Convert number to digits */
				{
					buf[idx++] = (n % 10) + '0';  /* Get last digit and convert to char */
					n /= 10;                      /* Remove last digit */
				}

				while (idx--)                /* Print digits in correct order */
				{
					write(1, &buf[idx], 1);  /* Write one digit at a time */
					count++;                 /* Count each digit printed */
				}
			}
			i += 2;                          /* Skip % and format character */
		}
		else if (format[i] == '%' && format[i + 1] == '%')  /* Handle %% */
		{
			write(1, "%", 1);                /* Print literal % */
			count++;                         /* Count it */
			i += 2;                          /* Skip both % symbols */
		}
		else if (format[i] == '%' && format[i + 1] == '\0')  /* % at end = invalid */
		{
			va_end(args);                   /* Clean up va_list */
			return (-1);                    /* Return error */
		}
		else                                /* Normal character (not a format specifier) */
		{
			write(1, &format[i], 1);        /* Print character as-is */
			count++;                        /* Count the character */
			i++;                            /* Move to next character */
		}
	}

	va_end(args);                           /* Clean up va_list */
	return (count);                         /* Return total number printed */
}
