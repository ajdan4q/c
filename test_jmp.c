/*
 * =====================================================================================
 *
 *       Filename:  test_jmp.c
 *
 *    Description:  setjmp and longjmp
 *
 *        Version:  1.0
 *        Created:  03/14/2013 02:54:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <setjmp.h>
#include "dbg.h"

static void f1 (int, int, int, int);
static void f2 (void);

static jmp_buf jmpbuf;
static int globval;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	int autoval;
	register int regival;
	volatile int volaval;
	static int statval;

	globval = 1; autoval = 2; regival = 3; volaval = 4; statval = 5;

	if (setjmp(jmpbuf) != 0)
	{
		printf("after longjmp:\n");
		printf("globval = %d, autoval = %d, regival = %d,"
				" volaval = %d, statval = %d\n",
				globval, autoval, regival, volaval, statval);
		exit(0);
	}

	/*
	 * Change variables after setjmp, but before longjmp.
	 */
	globval = 95; autoval = 96; regival = 97; volaval = 98;
	statval = 99;

	f1(autoval, regival, volaval, statval); /* never returns */

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

static void f1 (int i, int j, int k, int l)
{
	printf("in f1():\n");
	printf("globval = %d, autoval = %d, regival = %d,"
			" voloval = %d, statval = %d\n", globval, i, j, k, l);

	f2();
}

static void f2 (void)
{
	longjmp(jmpbuf, 1);
}
