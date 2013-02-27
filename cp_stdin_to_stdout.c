/*
 * =====================================================================================
 *
 *       Filename:  cp_stdin_to_stdout.c
 *
 *    Description:  use read, write function
 *
 *        Version:  1.0
 *        Created:  02/25/2013 07:15:27 AM
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

int main (int argc, char *argv[])
{
	int n;

	int bufsize;
	if (argc == 1)
		bufsize = 4096;
	else
		bufsize = atoi(argv[1]);

	char *buf = malloc(bufsize);
	if (buf == NULL) error_exit();
	
	//char buf[bufsize];

	// read return 0 when EOF, -num for errror
	while ((n = read(STDIN_FILENO, buf, bufsize)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n) /* read_size != write_size */
			log_info("write error.");
	if (n < 0)
		log_info("read error.");

	free(buf);
	exit(EXIT_SUCCESS);
}
