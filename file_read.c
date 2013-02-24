#include <stdio.h>

main()
{
    char c, line[1000], name[20], kb[2];
    int i=0, value;
    FILE *f = fopen("/proc/meminfo", "r");
    if( f != NULL)
        while((c=getc(f)) != EOF){
            if(c!='\n')
                line[i++]=c;
            else
            {
                line[i]='\0';
                //printf("%s\n", line);
                if(sscanf(line, "%s %i %s", name, &value, kb)==3)
                    printf("%s %i %s\n", name, value, kb);
                i=0;
            }
        }
        //printf("%c", c);
}
