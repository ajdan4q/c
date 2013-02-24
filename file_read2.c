#include <stdio.h>
#define LENGTH 1000

main()
{
    char line[LENGTH], name[20], kb[2];
    int value, match_count;
    FILE *f = fopen("/proc/meminfo", "r");
    if (f != NULL)
       while( fgets(line, LENGTH, f) != NULL) 
       {
           printf("line length ... %i\n", strlen(line));
           //fputs(line, stdout);
           /*
           if(sscanf(line, "%s %i %s", name, &value, kb) == 3)
               printf("%s %i %s\n", name, value, kb);
           if(sscanf(line, "%s", name) == 1)
               printf("%s\n", name);
               */
           match_count= sscanf(line, "%i", &value);
           //printf("%i\n", match_count);
           if(match_count == 1)
               printf("%i\n", value);
       }
}
