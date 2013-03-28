/*
 * =====================================================================================
 *
 *       Filename:  avoid_zombie.c
 *
 *    Description:  fork twice, avoid zombie process
 *
 *        Version:  1.0
 *        Created:  03/18/2013 08:06:27 AM
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
#include <sys/wait.h>
#include "dbg.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
		log_err("fork error");
	else if (pid == 0)	/* child */
	{
		if ((pid = fork()) < 0)
			log_err("fork error");
		else if (pid != 0)	/* first child */
			exit(0);

		// second child
		sleep(2);	/* sleep 2 seconds let its parent(first child) exit */
		printf("second child [%d], parent [%d]\n",
				getpid(), getppid());
		exit(0);
	}

	// parent
	if (waitpid(pid, NULL, 0) != pid)	/* wait for first child */
		log_err("waitpid error");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
