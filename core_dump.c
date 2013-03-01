/*
 * =====================================================================================
 *
 *       Filename:  core_dump.c
 *
 *    Description:  core dump test
 *
 *        Version:  1.0
 *        Created:  03/02/2013 01:01:55 AM
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
	char *p = NULL;
	printf("char %c\n", *p);
	return EXIT_SUCCESS;
}
