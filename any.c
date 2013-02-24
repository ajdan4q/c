#include <stdio.h>
#include <string.h>

#define NOT_FOUND -1

main()
{
    char* a = "abcdefgh";
    char* b = "bdh";
    char* pos;
    pos = strpbrk(a, b);
    printf("%s\n", pos++);
    pos = strpbrk(pos, b);
    printf("%s\n", pos++);
    pos = strpbrk(pos, b);
    printf("%s\n", pos);
}
