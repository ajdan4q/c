/*
 * =====================================================================================
 *
 *       Filename:  echoall.c
 *
 *    Description:  echo all args and environ
 *
 *        Version:  1.0
 *        Created:  03/18/2013 11:15:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;

	for (i = 0; i < argc; i++)	/* echo all command arguments */
		printf("argv[%d]: %s\n", i, argv[i]);

	for (ptr = environ; *ptr != 0; ptr++)	/* and all env strings */
		printf("%s\n", *ptr);

	exit(EXIT_SUCCESS);
}				/* ----------  end of function main  ---------- */
