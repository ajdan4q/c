/*
 * =====================================================================================
 *
 *       Filename:  cp_stdin_to_stdout2.c
 *
 *    Description:  use libc
 *
 *        Version:  1.0
 *        Created:  02/25/2013 08:02:58 PM
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

int main (void)
{
	int c;

	// getc eof or err return EOF
	// this test stdin EOF
	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF) /* putc return EOF when error */
			log_info("output error");

	// use ferror test stdin error
	if (ferror(stdin))
		log_info("input error");

	exit(EXIT_SUCCESS);
}
