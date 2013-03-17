/*
 * =====================================================================================
 *
 *       Filename:  sum_to_n.c
 *
 *    Description:  sum to n
 *
 *        Version:  1.0
 *        Created:  03/02/2013 08:41:24 PM
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

int sum (int n);
int sum2 (int n);

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "USAGE: %s sum sum\n", argv[0]);
		return EXIT_FAILURE;
	}

	printf("sum  %d\n", sum(atoi(argv[1])));
	printf("sum2 %d\n", sum2(atoi(argv[2])));

	return EXIT_SUCCESS;
}

/* sum 1 ... n */
int sum (int n)
{
	int result = 0;
	for (; n > 0; n = n - 2)
		result += n + (n - 1);
	return result;
}

int sum2 (int n)
{
	if (n < 1)
		return 0;
	return n + sum2(n - 1); /* non tail-recurisve, may be call stack overflow */
}
