/*
 * =====================================================================================
 *
 *       Filename:  seq_ten.c
 *
 *    Description:  use recursion print 1 ... 10. use tail-recursive function
 *
 *        Version:  1.0
 *        Created:  03/02/2013 02:01:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

//static int count = 1;

int main (void)
{
	static long count = 1;	/*  OK, why? executed only once */

	if (count > 10)
		return EXIT_SUCCESS;

	printf("%ld\n", count);

	count++;
	return main();
	/* 
	 * it it a tail-recursive function? yes
	 * should enable gcc -Os option optimize tail-function.
	 * man gcc, search 'recursive' */
}
