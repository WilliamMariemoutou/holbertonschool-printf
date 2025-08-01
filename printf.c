#include <stdarg.h>  /* For handling variable argument lists */
#include <unistd.h>  /* For write function */
#include <stdlib.h>  /* For malloc and free */

/**
 * print_char - Prints a single character to stdout
 * @c: The character to print
 *
 * Return: Number of characters printed (1)
 */
int print_char(char c)
{
    return write(1, &c, 1);  /* Write one character to stdout */
}

/**
 * print_string - Prints a string to stdout
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
    int count = 0;  /* Counter for printed characters */

    if (!str)  /* If the string is NULL */
        str = "(null)";  /* Print default null representation */

    while (*str)  /* Iterate through each character in string */
    {
        write(1, str++, 1);  /* Print character and move to next */
        count++;  /* Increment character count */
    }

    return count;  /* Return total printed characters */
}

/**
 * print_number - Prints an integer to stdout
 * @n: The number to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
    char buffer[11];  /* Buffer to hold digits (max for int + sign) */
    int i = 10;  /* Start from end of buffer */
    int count = 0;  /* Character count */
    unsigned int num;  /* Unsigned version of number */

    buffer[10] = '\0';  /* Null-terminate string */

    if (n == 0)
        return write(1, "0", 1);  /* Handle 0 directly */

    if (n < 0)
    {
        count += write(1, "-", 1);  /* Print minus sign */
        num = -n;  /* Convert to positive */
    }
    else
    {
        num = n;  /* Use number as is */
    }

    while (num > 0)
    {
        buffer[--i] = (num % 10) + '0';  /* Store digit character */
        num /= 10;  /* Move to next digit */
    }

    count += write(1, &buffer[i], 10 - i);  /* Print digits */

    return count;  /* Return total printed characters */
}

/**
 * _printf - Custom printf function supporting %c, %s, %%, %d and %i
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0, count = 0;  /* Loop index and total char count */
    va_list args;  /* Argument list */

    if (!format)  /* If format string is NULL */
        return -1;  /* Return error */

    va_start(args, format);  /* Initialize argument list */

    while (format[i])  /* Loop through format string */
    {
        if (format[i] != '%')  /* Normal character */
        {
            count += write(1, &format[i], 1);  /* Print it */
        }
        else  /* Handle format specifier */
        {
            i++;  /* Move to specifier character */
            if (!format[i])
                break;  /* End of string, break loop */
            if (format[i] == 'c')  /* Character */
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')  /* String */
                count += print_string(va_arg(args, char *));
            else if (format[i] == 'd' || format[i] == 'i')  /* Integer */
                count += print_number(va_arg(args, int));
            else if (format[i] == '%')  /* Percent sign */
                count += write(1, "%", 1);
            else
            {
                count += write(1, "%", 1);  /* Print invalid format start */
                count += write(1, &format[i], 1);  /* Then the unknown char */
            }
        }
        i++;  /* Move to next character */
    }

    va_end(args);  /* Cleanup argument list */

    return count;  /* Return total printed characters */
}

