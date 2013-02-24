#include <stdio.h>

main()
{
    FILE *f = fopen("test.txt", "w");
    fprintf(f, "this is a test2\n");
    fclose(f);
}
