#include <stdio.h>

void my_strcat(char *s, char *t);

main()
{
    char a[10] ="abc", b[] ="defg";
    my_strcat(a, b);
    printf("%s\n", a);

    return 0;
}

/* concat t to end of s */
void my_strcat(char *s, char *t)
{
    int i, j;
    i = j = 0;
    /* go to end of s */
    while (s[i] != '\0')
        i++;
    /* then cp t to end of s */
    // printf("%i\n", i);
    while ((s[i++] = t[j++]) != '\0')
        ;
}
