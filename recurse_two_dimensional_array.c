/*
 * =====================================================================================
 *
 *       Filename:  recurse_two_dimensional_array.c
 *
 *    Description:  recurse two-dimensional array
 *
 *        Version:  1.0
 *        Created:  03/03/2013 08:28:36 PM
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

/*
 * two-deminsional array must be specificed num of colums.
 * */
void recurse_array (int (*array)[10], int rows)
{
}

void loop_array (int (*array) [10], int rows, int columns)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < columns; j++)
			printf(( j == columns -1 ? "%d\n" : "%d "), array[i][j]);
}

int main (void)
{
	int a[][10] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
	};

	// recursive

	// double loop method
	loop_array(a, 2, 10);

	return EXIT_SUCCESS;
}
