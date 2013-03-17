/*
 * =====================================================================================
 *
 *       Filename:  for_loop_ten.c
 *
 *    Description:  use for print 1 ... 10
 *
 *        Version:  1.0
 *        Created:  03/02/2013 04:01:07 PM
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
	int i;
	for (i = 1; i <= 10; i++)
		printf("%d\n", i);
	return EXIT_SUCCESS;
}
