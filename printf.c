#include "main.h"
#include <stdarg.h> /*Access to variadic functions*/
#include <unistd.h>/*Gives us write()*/

/**
 *_printf - Produces output according to a format
 *@format: The format string
 *Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args; /*declare a list to hold arguments*/
	int i = 0; /* index for traversing format string*/
	int count = 0; /* to couunt number of characters printed*/
	int j = 0;

	if (format[0] == NULL)
		return(-1);
	va_start(args, format); /*initialize the argument list*/

	while (format[i] != '\0') /* loop through the format string*/
	{
		/* Check if we found a format specifier %c*/
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			char ch = va_arg(args, int); /*get the next argument as char*/
			write(1, &ch, 1); /*print that character*/
			count++; /*increment count*/
			i += 2; /*skip '%' and 'c'*/
		}
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            if (str == NULL)
                str = "(null)";
            for (j = 0; str[j] != '\0'; j++)
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
int main(void) {
    _printf("Hello World\n");
    _printf("%c\n", 'A');
    _printf("%s\n", "test");
    _printf("%%\n");
    return 0;
}		

