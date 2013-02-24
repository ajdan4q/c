#include <stdio.h>
#include <float.h>

main()
{
    // test float
    printf("test float\n");
    printf("maximum floating-point number %e\n", FLT_MAX);
    printf("decimal digits of precision %i\n", FLT_DIG);
    printf("minimum normalized floating-point number %e\n", FLT_MIN);
    // test double
    printf("\ntest double\n");
    printf("decimal digits of precision %i\n", DBL_DIG);
    printf("maximum double floating-point number %e\n", DBL_MAX);
    printf("minimum normalized double floating-point number %e\n", DBL_MIN);
    //char a='a';
    //printf("%c\n", a);
}
