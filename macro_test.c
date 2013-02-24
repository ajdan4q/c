#include <stdio.h>

#define filling "replacement"
#define max(a, b) ((a) > (b) ? (a) : (b))
#define dprint(s) printf(#s " %i\n", s)
#define dprint2(s) printf(#s " = %s\n", s)
#define paste(arg1, arg2) arg1 ## arg2
/* ## cat two arguments */

main()
{
    // invoke macro replacement
    dprint(10);
    dprint2("test");
    
    printf("a " "b\n"); /* string cat */
    printf(filling "\n");
    printf("max = %i\n", max(10,2));
    printf("%i\n", paste(1, 2));

    return 0;
}
