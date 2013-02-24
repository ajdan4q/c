#include <stdio.h>

main()
{
    /* number %[fieldwidth.decimal_point]f */
    printf("float expression  <%-6.2f>\n", 1.1); // 6 width, 2 decimal point
    printf("e     expression  <%.4e>\n", 10.1); // precision is 4
    printf("E     expression  <%.2E>\n", 10.1);
    printf("%i\n", '\0');
    printf("%i\n", '0');
    printf("%o\n", '0');
    printf("%x\n", '0');
    printf("%c\n", '0'+1);
    printf("%c\n", 'a'+1);
    printf("<%i>\n", "10");
    printf("<%i>\n", '1');
    printf("char a decimal value is %i\n", 'a');
    printf("char A decimal value is %i\n", 'A');
    /* 'a' > 'A', 'a' - 'A' = 32 */

    printf("%.*s\n", 2, "abcdefg");
    printf("%*s\n", 2, "abcdefg");
    /* %[.n] trim char str length, 
     * %[n] just keep max width, less than n, will padded space 
     * both int (float) and char string
     * */
    printf("5 / 2 = %i\n", 5 / 2);
}
