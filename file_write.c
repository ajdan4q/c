#include <stdio.h>

main()
{
    FILE *fp = fopen("test.txt", "w");
    putc('a', fp);
    putc('b', fp);
    putc('c', fp);
    putc('\n', fp);
    fclose(fp);
}
