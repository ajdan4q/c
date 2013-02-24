#include <stdio.h>

char* squeeze(char *sa, char *sb);

main()
{
    char a[] = "abcdefg"; /* character array-defined sting is free to change item */
    char *b = "deg"; /* point-defined string can not change */
    char *result = squeeze(a, b);
    int i;
    for (i = 0; result[i] != '\0'; i++)
        printf("%c", result[i]);
    printf("\n");
    printf("%s\n", result);
}

/* delete each character in sa that matches any character in string sb */
char* squeeze(char *sa, char *sb)
{
    /* save unmatches character has same effect to delete matches character*/
    /* for a in sb
     *  for b in sa
     *     if item1 == item2 then set match status and break inner-loop
     *  check match, not match -> add a to sb available sub-script
     */
    int i, j, h, match;
    h = match = 0;
    for (i = 0; sa[i] != '\0'; i++)
    {
        /* while sa[i] not in sb, add to sa[i++] */
        for (j = 0; sb[j] != '\0'; j++)
        {
            if (sb[j] == sa[i])
            {
                match = 1;
                break;
            }
        }

        if (!match) /* if sa[i] not in sb */
            sa[h++] = sa[i];
        /* reset match status */
        match = 0;
    }
    sa[h] = '\0';
    return sa;
}
