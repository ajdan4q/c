/*
 * =====================================================================================
 *
 *       Filename:  create_file_with_hole.c
 *
 *    Description:  use write create file with hole
 *
 *        Version:  1.0
 *        Created:  02/27/2013 12:05:01 AM
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
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIH";

int main (void)
{
	int fd;
	off_t offset;

	/* mode = mode & ~umask */
	// wr-r--r--
	mode_t mode = S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR;
//	wr-------
//	mode_t mode = S_IRUSR | S_IWUSR;
	if (((fd = creat("file.hole", mode)) < 0))
		perror("create");

	// init offset is 0
	offset = lseek(fd, 0, SEEK_CUR);
	printf("create file, offset is %d\n", (int) offset);

	if (write(fd, buf1, 10) != 10)
		perror("write");

	// get current offset of fd
	offset = lseek(fd, 0, SEEK_CUR);
	printf("after write 10 byte, offset is %d\n", (int) offset);

	if (lseek(fd, 16384, SEEK_SET) == -1)
		perror("lseek");
	/* offset now = 16384 */

	offset = lseek(fd, 0, SEEK_CUR);
	printf("set offset to %d\n", (int) offset);

	if (write(fd, buf2, 10) != 10)
		perror("write");
	/* offset now = 16394 */

	offset = lseek(fd, 0, SEEK_CUR);
	printf("after write 10 byte, offset is %d\n", (int) offset);

	// get file size, just like ls -l
	offset = lseek(fd, 0, SEEK_END);
	printf("file size is %d\n", (int) offset);

	//close(fd);
	exit(0);
}
