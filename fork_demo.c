/*
 * =====================================================================================
 *
 *       Filename:  fork_demo.c
 *
 *    Description:  process and child process
 *
 *        Version:  1.0
 *        Created:  03/14/2013 08:59:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include "dbg.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	log_info("Main process run ...");

	pid_t pid = fork();	/* parent and child continue run, after fork() */

	if (pid == 0)	/* child process */
	{
		log_info("[%d] I am child process, ppid is %d",
				(int) getpid(), (int) getppid());
	}
	else if (pid < 0)
	{
		err_exit("fork");
	}
	else
	{
		sleep(20);
		log_info("[%d] Main process continue run, my child id is %d",
				(int) getpid(), (int) pid);
	}

	/* both of process and child process will run following ... */
	log_info("[%d] Process go to return [%d]", (int) getpid(), (int) getpgrp());

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
