#include <stdio.h>
#include "main.h"  /* Your header file with _printf prototype */

int main(void)
{
    int len1, len2;
    char *null_str;

    null_str = NULL;  /* Declare and initialize here to avoid mixed declarations */

    /* Basic test */
    len1 = _printf("Hello, world!\n");
    len2 = printf("Hello, world!\n");
    printf("_printf len: %d | printf len: %d\n\n", len1, len2);

    /* Character test */
    len1 = _printf("Character: [%c]\n", 'A');
    len2 = printf("Character: [%c]\n", 'A');
    printf("_printf len: %d | printf len: %d\n\n", len1, len2);

    /* String test */
    len1 = _printf("String: [%s]\n", "Test String");
    len2 = printf("String: [%s]\n", "Test String");
    printf("_printf len: %d | printf len: %d\n\n", len1, len2);

    /* Percent sign test */
    len1 = _printf("Percent: [%%]\n");
    len2 = printf("Percent: [%%]\n");
    printf("_printf len: %d | printf len: %d\n\n", len1, len2);

    /* Null string test - cast NULL to char * */
    len1 = _printf("Null string: [%s]\n", (char *)null_str);
    len2 = printf("Null string: [%s]\n", (char *)null_str);
    printf("_printf len: %d | printf len: %d\n\n", len1, len2);

    /* Integer test */
    len1 = _printf("INT_MIN: [%d]\n", -2147483647 - 1);
    len2 = printf("INT_MIN: [%d]\n", -2147483647 - 1);
    printf("_printf len: %d | printf len: %d\n\n", len1, len2);

    return 0;
}
