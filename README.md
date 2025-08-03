##NAME

_printf – custom function that prints formatted output, similar to printf

##SYNOPSIS

#include "main.h"

int _printf(const char *format, ...);

##DESCRIPTION

The _printf function prints formatted text to standard output. It processes a format string containing ordinary characters and format specifiers (starting with %). Each format specifier is replaced with corresponding arguments provided after the format string.

##FORMAT SPECIFIERS

The following format specifiers are supported:

%c – Prints a single character

%s – Prints a string

%% – Prints a percent sign

%d – Prints a signed decimal integer

%i – Prints a signed decimal integer

##PARAMETERS

format: A constant character string composed of zero or more characters and format specifiers. It dictates how the output is formatted.

... (ellipsis): A variable number of arguments that are used to replace the format specifiers.

##RETURN VALUE

Returns the total number of characters printed (excluding the null byte).

Returns -1 if the format string is NULL.

##ERRORS

If format is NULL, _printf returns -1.

If an unknown format specifier is encountered (e.g., %x), _printf prints it as is (e.g., %x → %x).

##EXAMPLES

int result = _printf("Hello %s! Your score is %d%%\n", "Tom", 90);

Output:

Hello Tom! Your score is 90%

Return value:
Returns the number of characters printed, in this case: 30.

##LIMITATIONS

No support for flags (+, -, 0, etc.)

No width or precision modifiers

No support for format specifiers like %u, %o, %x, %f, etc.

No support for length modifiers (l, ll, etc.)

##AUTHORS

Written by William and Meenakshee 
