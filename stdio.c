#include <stdio.h>

main()
{
    char c;
    // standard input
    c = getc(stdin);

    // standard output 
    putc(c, stdout);
    putc('\n', stdout);

    // standard error
    putc(c, stderr);
    putc('\n', stderr);
}
