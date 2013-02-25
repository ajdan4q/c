/*
 * =====================================================================================
 *
 *       Filename:  list_file.c
 *
 *    Description:  list file in a directory
 *
 *        Version:  1.0
 *        Created:  02/25/2013 05:35:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include "dbg.h"

int main (int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *entp;

	check(argc == 2, "USAGE: %s dirname", argv[0]);

	dirp = opendir(argv[1]);
	check(dirp != NULL, "opendir");

	while ((entp = readdir(dirp)) != NULL)
		printf("%s\n", entp->d_name);

	closedir(dirp);
	exit(EXIT_SUCCESS);
error:
	exit(EXIT_FAILURE);
}
