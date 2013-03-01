/*
 * =====================================================================================
 *
 *       Filename:  utime_usage.c
 *
 *    Description:  utime() demo
 *
 *        Version:  1.0
 *        Created:  03/01/2013 04:58:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "dbg.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <utime.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main (int argc, char *argv[])
{
	struct stat statbuf1, statbuf2;
	// get last-access-time and last-modified-time
	if (stat("file1.txt", &statbuf1) < 0)
		log_err("stat file1.txt");

	if (stat("file2.txt", &statbuf2) < 0)
		log_err("stat file2.txt");

	// truncate file with open O_TRUNC
	int fd;
	if ((fd = open("file1.txt", O_TRUNC | O_WRONLY)) < 0)
		log_err("open file1.txt");
	if (close(fd) < 0)
		log_err("close fd");

	if ((fd = open("file2.txt", O_TRUNC | O_WRONLY)) < 0)
		log_err("open file2.txt");
	if (close(fd) < 0)
		log_err("close fd");

	// reset file file-access-time and last-modified-time
	struct utimbuf timebuf;

	timebuf.actime = statbuf1.st_atime;
	timebuf.modtime = statbuf1.st_mtime;
	if (utime("file1.txt", &timebuf) < 0)
		log_err("utime file1.txt");

	timebuf.actime = statbuf2.st_atime;
	timebuf.modtime = statbuf2.st_mtime;
	if (utime("file2.txt", &timebuf) < 0)
		log_err("utime file2.txt");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
