/*
 * =====================================================================================
 *
 *       Filename:  int_and_array.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/05/2013 12:31:11 AM
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

int main (int argc, char *argv[])
{
	int arr[10] = {0};	/* name of array pointer to first element */

	int *intp = arr;

	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", *intp++);
	puts("");

	return EXIT_SUCCESS;
}
