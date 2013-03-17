/*
 * =====================================================================================
 *
 *       Filename:  pass_by_reference.c
 *
 *    Description:  simulate pass by reference.
 *
 *        Version:  1.0
 *        Created:  03/04/2013 05:01:44 AM
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

void f (int *);
void f2 (int **);
int *f3 (void);

int main (void)
{
	int *a;

	f(a);		/* pass a's content to f, pass by value */
	printf("%d\n", *a);

	f2(&a);		/* pass a's address to f, simulate pass by reference */
	printf("%d\n", *a);

	a = f3();	/* return allocated mem addr, just like malloc */
	printf("%d\n", *a);

	return EXIT_SUCCESS;
}

void f (int *arg)
{
	/* the called function alters only the passed copy of the pointer. */
	static int dummy = 1;
	arg = &dummy;
	/* copy dummy addr to arg (automatic variable), 
	 * without change content that arg point to.
	 * after return from function, arg, dummy dispear,
	 * but allocted space still valid
	 * */
}

void f2 (int **arg)	/* accept pointer 's address which point to int */
{
	static int dummy = 2;
	*arg = &dummy;	/* int *arg = int *dummy */
}

/* 
 * within function alloced memory and inited (this case using static variable)
 * then return memory address to caller
 * caller can derefered return's addr, get dummy's value '3'
 * */
int *f3 (void)
{
	static int dummy = 3;
	return &dummy;
}
