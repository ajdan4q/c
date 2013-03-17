/*
 * =====================================================================================
 *
 *       Filename:  environ.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/13/2013 10:21:26 PM
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

extern  char *environ[];

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[]) {

	char **env = environ;

	while (*env != NULL)
		printf("%s\n", *env++);

	char *envar = NULL;

	envar = getenv("HOME");
	if (envar != NULL)
		printf("HOME = %s\n", envar);

	envar = getenv("PWD");
	if (envar != NULL)
		printf("PWD  = %s\n", envar);

	envar = getenv("PATH");
	if (envar != NULL)
		printf("PATH = %s\n", envar);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
