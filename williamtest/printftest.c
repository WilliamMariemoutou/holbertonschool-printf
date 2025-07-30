#include "main.h"
#include <stdarg.h>  // for va_list, va_start, va_arg, va_end
#include <unistd.h>  // for write()

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    if (format == NULL)
        return (-1);  // handle NULL input

    va_start(args, format);  // start processing variable arguments

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            char ch = va_arg(args, int);
            write(1, &ch, 1);
            count++;
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            if (str == NULL)
                str = "(null)";
            for (int j = 0; str[j] != '\0'; j++)
            {
                write(1, &str[j], 1);
                count++;
            }
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            write(1, "%", 1);
            count++;
            i += 2;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }

    va_end(args);
    return (count);
}

int main(void)
{
    int count1, count2;

    count1 = _printf("Hello, World!\n");
    count2 = printf("Hello, World!\n");

    _printf("Printed %d characters with _printf\n", count1);
    printf("Printed %d characters with printf\n", count2);

    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Test");
    _printf("Percent: %%\n");
    _printf("NULL string: %s\n", NULL);
    _printf("Mixed: %c %s %% Done!\n", 'Z', "Go");

    return (0);
}

