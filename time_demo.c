/*
 * =====================================================================================
 *
 *       Filename:  time_demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/13/2013 03:56:40 AM
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
#include <time.h>
#include <sys/time.h>

int main (void)
{
	time_t t;

	// time and gettimeofday
	t = time(NULL);
	if (t == ((time_t) - 1))
		perror("time");

	printf("time %d\n", (int) t);

	struct timeval tv;
	int ret;

	ret = gettimeofday(&tv, NULL);
	if (ret < 0)
		perror("gettimeofday");

	printf("gettimeofday %d %d\n", (int) tv.tv_sec, (int) tv.tv_usec);

	// gmtime and localtime
	struct tm *tmp;
	tmp = gmtime(&t);
	if (tmp == NULL)
		perror("gmtime");

	printf("gmtime %d %d %d %d %d %d %d %d %d\n", 
			tmp->tm_sec, tmp->tm_min, tmp->tm_hour,
			tmp->tm_mday, tmp->tm_mon, tmp->tm_year,
			tmp->tm_wday, tmp->tm_yday, tmp->tm_isdst);

	tmp = localtime(&t);
	if (tmp == NULL)
		perror("localtime");

	printf("localtime %d %d %d %d %d %d %d %d %d\n", 
			tmp->tm_sec, tmp->tm_min, tmp->tm_hour,
			tmp->tm_mday, tmp->tm_mon, tmp->tm_year,
			tmp->tm_wday, tmp->tm_yday, tmp->tm_isdst);

	// mktime
	printf("mktime %d\n", (int) mktime(tmp));

	// asctime and ctime
	printf("asctime %s", asctime(tmp));
	printf("ctime %s", ctime(&t));

	// strftime - string - format - time
	char buf[20];
	size_t st;
	st = strftime(buf, 20, "%F %T", tmp);
	printf("strftime %s\n", buf);

	exit(EXIT_SUCCESS);
}
