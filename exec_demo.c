/*
 * =====================================================================================
 *
 *       Filename:  exec_demo.c
 *
 *    Description:  execle and execlp demo usage
 *
 *        Version:  1.0
 *        Created:  03/18/2013 11:30:38 PM
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
#include <stdio.h>

char *env_init[] = {"USER=unknow", "PATH=/tmp", NULL};

int main (void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid == 0)	/* specify pathname, environment */
	{
		if (execle("./echoall", "echoall", "myarg1",
			"MY ARG2", (char *) NULL, env_init) < 0)
			perror("execle");
	}

	if (waitpid(pid, NULL, 0) < 0)
		perror("waitpid");

	if ((pid = fork()) < 0)
		perror("fork");
	else if (pid == 0)
	{
		/* cp echoall to /root/bin or other PATH */
		if (execlp("echoall", "echoall", "only 1 arg", (char *)NULL) < 0)
			perror("execlp");
	}

	exit(EXIT_SUCCESS);
}
