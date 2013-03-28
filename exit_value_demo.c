/*
 * =====================================================================================
 *
 *       Filename:  exit_value_demo.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/18/2013 07:24:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "dbg.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  pr_exit
 *  Description:
 * =====================================================================================
 */
void pr_exit (int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit value = %d\n",
			WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
			WTERMSIG(status),
#ifdef WCOREDUMP
			WCOREDUMP(status) ? " (core file generated)" : "");
#else
			"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
			WSTOPSIG(status));
}		/* -----  end of function pr_exit  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main (void)
{
	pid_t pid;
	int status;

	// fork1
	if ((pid = fork()) < 0)
		log_err("fork errorr");
	else if (pid == 0)	/* child */
		exit(7);	/* normal exit with value 7 */

	if (wait(&status) != pid)
		log_err("wait error");
	pr_exit(status);

	// fork2
	if ((pid = fork()) < 0)
		log_err("fork error");
	else if (pid == 0)	/* child */
		abort();	/* generates SIGABRT */

	if (wait(&status) != pid)
		log_err("wait error");
	pr_exit(status);

	// fork3
	if ((pid = fork()) < 0)
		log_err("fork error");
	else if(pid == 0)
		status /= 0;	/* divide by 0 */

	if (wait(&status) != pid)
		log_err("wait error");
	pr_exit(status);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
