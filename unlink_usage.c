/*
 * =====================================================================================
 *
 *       Filename:  unlink_usage.c
 *
 *    Description:  open a file and unlink it, sleep some seconds, then exit
 *
 *        Version:  1.0
 *        Created:  03/01/2013 02:10:53 AM
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
#include <fcntl.h>

int main (void)
{
	if (open("tempfile.txt", O_RDWR) < 0)
		log_err("open tempfile.txt");

	if (unlink("tempfile.txt") < 0)
		log_err("unlink tempfile.txt");

	log_info("file unlinked");
	sleep(15);
	log_info("done");

	exit(0);
}

