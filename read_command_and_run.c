/*
 * =====================================================================================
 *
 *       Filename:  read_command_and_run.c
 *
 *    Description:  read command and run it without command arguments
 *
 *        Version:  1.0
 *        Created:  02/25/2013 08:52:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "dbg.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#define BUF_SIZE 1024

static void sig_int (int); /* our signal-catching function */

int main (void)
{
	char buf[BUF_SIZE];
	pid_t pid;
	int status;

	// catch 'SIGINI' signal, envoke 'sig_int' signal handler
	if (signal(SIGINT, sig_int) == SIG_ERR)
		perror("signal");

	printf("%% ");	/* set prompt */
	/* fgets() return NULL, EOF or error */
	while (fgets(buf, BUF_SIZE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';

		/* fork return child pid to parent
		 * return 0 to child
		 * return -1 to parent if error occur, no child create 
		 * */
		if ((pid = fork()) < 0)
			perror("fork");
		else if (pid == 0)	/* child */
		{
			execlp(buf, buf, (char *) 0);	/* do PATH search */
			/* if execlp return, error occur */
			perror(buf);
			exit(EXIT_FAILURE);
		}

		/* parent */
		/* waitpid return -1, if error */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			perror("waitpid");
		printf("%% ");
	}
	if (ferror(stdin))
		log_err("input error");
	exit(EXIT_SUCCESS);
}

static void sig_int (int signo)
{
	printf("interrupt\n%% ");
}
