#include <stdio.h>

main(int argc, char *argv[])
{
    //int i;
    for( ; *++argv != '\0'; )
    //for( ; (++argv) != NULL; )
        printf("%s ", *argv);
    printf("\n");
    
    return 0;
}
