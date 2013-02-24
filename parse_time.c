#include <stdio.h>

main()
{
    char line[100];
    int hour, minute, second;
    FILE *f = fopen("time.txt", "r");
    if (f != NULL)
        while(fgets(line, 100, f) != NULL){
            fputs(line, stdout);
            if(sscanf(line, "Tue Jan  1 %i:%i:%i", &hour, &minute, &second)==3)
                printf("%i:%i:%i\n", hour, minute, second);
        }
}
