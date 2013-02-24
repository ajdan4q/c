#include <stdio.h>

main()
{
    int i, lim;
    char c, s[100];
    for(i=0; i < lim -1; ++i)
    {
        if ((c = getchar()) == '\n')
	    break;
	if (c == EOF)
	    break;
	// do sth...
     }
}
