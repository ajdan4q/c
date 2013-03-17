/*
 * =====================================================================================
 *
 *       Filename:  fork_demo2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/14/2013 09:41:53 PM
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
#include <sys/wait.h>

int glob = 6;
char buf[] = "a write to stdout\n";

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	int var;
	pid_t pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		log_err("write");

	printf("before fork\n");	/* we don't flush stdout */

	if ((pid = vfork()) < 0)
		log_err("fork");
	else if (pid == 0)	/* child */
	{
		glob++;
		var++;
		log_info("[%d] Child process", (unsigned int) getpid());
		_exit(0);
	}
//	else
//		sleep(2);	/* parent */

	int status;

	if ((pid = wait(&status)) > 0)
		log_info("process %d exit value [%d]", (int) pid, status);
	else
		log_err("wait");

	printf("pid = %d, glob = %d, var = %d\n",
			getpid(), glob, var);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
