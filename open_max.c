/*
 * =====================================================================================
 *
 *       Filename:  open_max.c
 *
 *    Description:  determine the number of file descriptors
 *
 *        Version:  1.0
 *        Created:  03/01/2013 09:53:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "dbg.h"
#include <unistd.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

/* 
 * If OPEN_MAX is indeterminate, we're not
 * guaranteed that this is adequate.
 * */
#define OPEN_MAX_GUESS 256

long open_max (void)
{
	if (openmax == 0)
	{
		errno = 0;
		if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
		{
			if (errno == 0)
				openmax = OPEN_MAX_GUESS;	/* indeterminate */
			else
				log_err("sysconf error for _SC_OPEN_MAX");
		}
		log_info("open max get from sysconf");
	}

	return openmax;
}

#if 0
int main (void)
{
	long openmax = open_max();
	printf("open_max is %ld\n", openmax);
	return 0;
}
#endif
