/*
 * =====================================================================================
 *
 *       Filename:  print_uid_gid.c
 *
 *    Description:  getuid and getgid
 *
 *        Version:  1.0
 *        Created:  02/26/2013 02:34:53 AM
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
#include <stdio.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

int main ( int argc, char *argv[] )
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
