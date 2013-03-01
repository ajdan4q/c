/*
 * =====================================================================================
 *
 *       Filename:  access_usage.c
 *
 *    Description:  access() function usage
 *
 *        Version:  1.0
 *        Created:  02/28/2013 09:06:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <file_name>\n", argv[0]);
		exit(1);
	}

	// return 0 on sucess, return -1 err
	if (access(argv[1], R_OK) < 0)
		perror("access R_OK");
	else
		printf("acess R_OK\n");

	if (open(argv[1], O_RDONLY) < 0)
		perror("open O_RONLY");
	else
		printf("open O_RONLY OK\n");

	return 0;
}
