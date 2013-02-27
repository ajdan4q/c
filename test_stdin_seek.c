/*
 * =====================================================================================
 *
 *       Filename:  test_stdin_seek.c
 *
 *    Description:  test stdio lseek
 *
 *        Version:  1.0
 *        Created:  02/26/2013 11:39:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cant not seek\n");
	else
		printf("seek OK\n");
	exit(0);
}
