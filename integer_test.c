#include <stdio.h>
#include <limits.h>
#include <float.h>

#define max_value_of "maximum value of "
#define min_value_of "minimum value of "
#define ma_v_of(type, value) printf("maximum value of %s %i\n", type, value)
#define mi_v_of(type, value) printf("minimum value of %s %i\n", type, value)

main()
{
    
    // bits in a char
    printf("bits in a char                  %hi\n", CHAR_BIT);

    // test int and char
    printf("maximum value of char           %i\n", CHAR_MAX);
    printf("maximum value of signed char    %i\n", SCHAR_MAX);
    printf("maxinum value of unsigned char  %i\n", UCHAR_MAX);
    printf("minimum value of char           %i\n", CHAR_MIN);
    printf("minimum value of signed char    %i\n", SCHAR_MIN);
    printf("maximum value of int            %i\n", INT_MAX);
    printf("minimum value of int            %i\n", INT_MIN);
    printf("maximum value of unsigned int   %u\n", UINT_MAX);
    printf("maximum value of signed short   %i\n", SHRT_MAX);
    printf("minimum value of signed short   %i\n", SHRT_MIN);
    printf("maximum value of unsigned short %u\n", USHRT_MAX);
    printf("maximum value of long           %i\n", LONG_MAX);
    printf("minimum value of long           %i\n", LONG_MIN);
    printf("maximum value of unsigned long  %u\n", ULONG_MAX);
    // signed use 'i', unsigned use 'u'

    /* use macro substitution */
    printf(max_value_of "unsigned short %hu\n", USHRT_MAX);
    ma_v_of("unsigned short", USHRT_MAX);
    mi_v_of("signed short", SHRT_MIN);

    return 0;
}
