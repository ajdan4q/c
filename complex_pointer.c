/*
 * =====================================================================================
 *
 *       Filename:  complex_pointer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2013 09:14:02 PM
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

int main (void)
{
	int *(*a)[3][4];
	/* 
	 * a: 
	 * point to 3 * 4 two dimensional array,
	 * each element is pointer to int
	 * */

	/* pointer to two-dimensional array */
	printf("sizeof(a)	%d\n", sizeof(a));

	/* two-dimensional array, rows * columns * sizeof(int *) */
	printf("sizeof(*a)	%d\n", sizeof(*a));

	/* row of two-dimensional array, columns * sizeof(int *) */
	printf("sizeof(**a)	%d\n", sizeof(**a));

	/* first element of first row of array, sizeof(int *) */
	printf("sizeof(***a)	%d\n", sizeof(***a));

	/* defered element of array, is int. sizeof(int) */
	printf("sizeof(****a)	%d\n", sizeof(****a));

	return EXIT_SUCCESS;
}

