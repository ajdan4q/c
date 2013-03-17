/*
 * =====================================================================================
 *
 *       Filename:  power_demo.c
 *
 *    Description:  pow()
 *
 *        Version:  1.0
 *        Created:  03/02/2013 03:07:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
	printf("pow(2, 0)  = %.0f\n", pow(2, 0));
	printf("pow(2, 8)  = %.0f\n", pow(2, 8));
	printf("pow(2, 16) = %.0f\n", pow(2, 16));
	printf("pow(2, 24) = %.0f\n", pow(2, 24));
	printf("pow(2, 32) = %.0f\n", pow(2, 32));
	return EXIT_SUCCESS;
}
