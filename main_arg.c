#include <stdio.h>

/* printf can direct print poiter ? */
/* argv is an array of character pointer */
main(int argc, char *argv[])
{
    int i;
    if (argc == 1)
        printf("Usage : %s arg1 arg2 ...\n", argv[0]);
    else
        for(i = 1; i < argc; i++ )
            printf((argc-1==i ? "%s\n" : "%s "), argv[i] );

    return 0;
}
