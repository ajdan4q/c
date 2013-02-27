/*
 * =====================================================================================
 *
 *       Filename:  verify_open_append.c
 *
 *    Description:  open() for readwrite with append flag, test lseek, write()
 *
 *
 *        Version:  1.0
 *        Created:  02/27/2013 10:49:19 PM
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
#include "dbg.h"
#define _XOPEN_SOURCE  500
#include <fcntl.h>


int main (void)
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int oflag = O_RDWR | O_APPEND | O_CREAT | O_EXCL;

	fd = open("file_append", oflag, mode);
	if (fd < 0) error_exit();

	// write some characters for test
	char *a = "abcdefg";
	ssize_t s = write(fd, a, 7);
	if (s != 7) error_exit();

	// lseek test, reset file offset
	if (lseek(fd, 0, SEEK_SET) < 0)
		log_err("lseek");

	// read from file of start test
	char b[3];
	if (read(fd, b, 3) == 3)
	{
		log_info("first 3 character");
		write(STDOUT_FILENO, b, 3);
	}
	else
		log_err("read");

	// lseek and override data use write with append flag
	if (write(fd, "DEFG", 4) == 4)
	{
		log_info("file content");
		fdatasync(fd);

		off_t len = lseek(fd, 0, SEEK_END);
		if (len < 0) log_err("lseek");

		char fresult[len];
		lseek(fd, 0, SEEK_SET); // set to begin of file
		read(fd, fresult, len);
		write(STDOUT_FILENO, fresult, len);
	}
	else
		log_err("write");

	return EXIT_SUCCESS;

	/* 
	 * with O_APPEND oflag, seek() and write() can not override data
	 * but can seek with lseek()
	 * */
}
