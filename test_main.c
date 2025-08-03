#include "main.h"
#include <stddef.h>  /* For NULL */

int main(void)
{
    _printf("Hello %s!\n", "World");
    _printf("Character: %c\n", 'A');
    _printf("Percent sign: %%\n");
    _printf("Empty string: %s\n", "");
    _printf("Null string: %s\n", NULL);

    return (0);
}
