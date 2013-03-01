/*
 * =====================================================================================
 *
 *       Filename:  umask_usage.c
 *
 *    Description:  umask() function demo
 *
 *        Version:  1.0
 *        Created:  02/28/2013 10:05:17 PM
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
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (void)
{
	umask(0);

	if (creat("foo.txt", RWRWRW) < 0)
		log_err("");

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (creat("bar.txt", RWRWRW) < 0)
		log_err("");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
