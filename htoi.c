#include <stdio.h>
#include <ctype.h>

main()
{
    char s[] = "0Xa23";
    int i = htoi(s);
    printf("%i\n", i);
    printf("%s\n", s);
}

/* hex to int, 0-9,a-f,A-F */
int htoi(char *s)
{
    int i, n;
    n = 0;
    for (i=0; s[i] != '\0'; ++i)
    {
        /* skip 0x or 0X */
        if (i == 0 && s[i] == '0')
	        continue;
	    if (i == 1 && (s[i] == 'x' || s[i] == 'X'))
	        continue;
	    /* accept 0-9, a-f, A-F */
	    if (isdigit(s[i]) || (s[i] >= 'a' && s[i] <='f') || (s[i] >='A' && s[i]<='F'))
	        if (isalpha(s[i]))
	            n = n*10 + (toupper(s[i]) - 55); /* UPPER - 55 GET IT dicimal present value a-f -> 10..15 */
	        else
	            n = n*10 + (s[i] - '0'); /* dicimal char - '0' get it char value 0-9 */
    }
    return n;
}
