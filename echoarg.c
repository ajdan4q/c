/*
 * =====================================================================================
 *
 *       Filename:  echoarg.c
 *
 *    Description:  echo args
 *
 *        Version:  1.0
 *        Created:  03/13/2013 10:00:07 PM
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
	char **args = argv;

	for(; *args != NULL; args++)
		printf("argv[%d]: %s\n", args - argv, *args);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
