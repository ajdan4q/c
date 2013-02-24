#include <stdio.h>

#define LEN 10
// global and static uninit variable set to zero
// local uninit variable generate random value

// global variables
/*
char char_arr[LEN];
short short_arr[LEN];
int int_arr[LEN];
long long_arr[LEN];
float float_arr[LEN];
double double_arr[LEN];
*/

main()
{
    // local variables
    char char_arr[LEN];
    short short_arr[LEN];
    int int_arr[LEN];
    long long_arr[LEN];
    float float_arr[LEN];
    double double_arr[LEN];
    // static variables
    /*
    static char char_arr[LEN];
    static short short_arr[LEN];
    static int int_arr[LEN];
    static long long_arr[LEN];
    static float float_arr[LEN];
    static double double_arr[LEN];
    */

    int i;
    for (i=0; i<LEN; i++)
    {
        printf("char_arr  's   char init value %i\n", char_arr[i]);
        printf("short_arr 's  short init value %i\n", short_arr[i]);
        printf("int_arr   's    int init value %i\n", int_arr[i]);
        printf("long_arr  's   long init value %li\n", long_arr[i]);
        printf("float_arr 's  float init value %f\n", float_arr[i]);
        printf("double_arr's double init value %f\n", double_arr[i]);
        printf("%i\n", i);
    }
}
