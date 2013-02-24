#include <stdio.h>
#define MAX 1000

main()
{
    char c, line[MAX], name[20], kb[2];
    int i=0, value;
    FILE *f = fopen("/proc/meminfo", "r");
    if( f != NULL)
        while(fgets(line, MAX, f)!=NULL)
            //puts(line); // add newline '\n'
            fputs(line, stdout);
}
