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

int main (void)
{
	int n;
	const int bufsize = 4096;
	char buf[bufsize];

	// read return 0 when EOF, -num for errror
	while ((n = read(STDIN_FILENO, buf, bufsize)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n) /* read_size != write_size */
			log_info("write error.");
	if (n < 0)
		log_info("read error.");

	exit(EXIT_SUCCESS);
}
