/*
 * =====================================================================================
 *
 *       Filename:  sig_catch.c
 *
 *    Description:  signal handler for SIGUSR1 and SIGUSR2
 *
 *        Version:  1.0
 *        Created:  03/22/2013 02:21:35 AM
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
#include <signal.h>
#include <unistd.h>

static void sig_usr (int signo);

int main (void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		log_err("can't not catch SIGUSR1");

	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		log_err("can't not catch SIGUSR@");

	for ( ; ; )
		pause();
}

static void sig_usr (int signo)
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		log_err("received signal %d", signo);
}
