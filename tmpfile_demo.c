/*
 * =====================================================================================
 *
 *       Filename:  tmpfile_demo.c
 *
 *    Description:  temfile() usage
 *
 *        Version:  1.0
 *        Created:  03/10/2013 06:01:42 AM
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
#define MAXLINE 20

int main (void)
{
	FILE *fp = tmpfile();
	if (fp == NULL)
		perror("tmpfile");

	if (fputs("one lines\n", fp) == EOF)
		fputs("fputs error\n", stderr);

	rewind(fp);

	char buf[MAXLINE];

	if (fgets(buf, MAXLINE, fp) == NULL)
		if (ferror(fp))
			fputs("fgets error\n", stderr);

	fputs(buf, stdout);

	return EXIT_SUCCESS;
}
