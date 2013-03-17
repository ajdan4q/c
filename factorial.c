/*
 * =====================================================================================
 *
 *       Filename:  factorial.c
 *
 *    Description:  factorial
 *
 *        Version:  1.0
 *        Created:  03/03/2013 07:03:02 PM
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

int factorial (int);

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <0...n> \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int val = atoi(argv[1]);
	printf("%d\n", factorial(val));
	return EXIT_SUCCESS;
}

int factorial (int n)
{
	if (n == 0)
		return  1;

	return n * factorial(n - 1);
}
