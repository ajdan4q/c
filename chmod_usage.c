/*
 * =====================================================================================
 *
 *       Filename:  chmod_usage.c
 *
 *    Description:  chmod() usage
 *
 *        Version:  1.0
 *        Created:  02/28/2013 10:32:00 PM
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
#include <sys/stat.h>
#include <fcntl.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main (int argc, char *argv[])
{
	struct stat statbuf;

	/* turn on set-group-ID and turn off group-execute */
	if (stat("foo.txt", &statbuf) < 0)
		log_err("stat foo.txt");
	if (chmod("foo.txt", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		log_err("chmod foo.txt");

	/* set obsolute mode to "rw-r--r--" */
	if (chmod("bar.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		log_err("chmod bar.txt");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
