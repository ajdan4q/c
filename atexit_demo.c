/*
 * =====================================================================================
 *
 *       Filename:  atexit_demo.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/13/2013 08:12:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "dbg.h"
#include <unistd.h>

static void exit1 (void);
static void exit2 (void);
static void exit3 (void);

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	if (atexit(exit1) != 0)
		log_err("can not register exit1");

	if (atexit(exit1) != 0)
		log_err("can't register exit1");

	if (atexit(exit2) != 0)
		log_err("can't register exit2");

	if (atexit(exit3) != 0)
		log_err("can not register exit3");

	return EXIT_SUCCESS;
	_exit(0);
}				/* ----------  end of function main  ---------- */

static void exit1 (void)
{
	printf("First exit handler\n");
}

static void exit2 (void)
{
	printf("Second exit handler\n");
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  exit3
 *  Description:
 * =====================================================================================
 */
static void exit3 (void)
{
	printf("Third exit handler\n");
}		/* -----  end of static function exit3  ----- */
