/*
 * =====================================================================================
 *
 *       Filename:  path_alloc.c
 *
 *    Description:  dynamically allocate space for a pathname
 *
 *        Version:  1.0
 *        Created:  03/01/2013 09:16:39 PM
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
#include <limits.h>
#include <unistd.h>

#ifdef PATH_MATH
static int pathmax = PATH_MAX;	/* have defined: 4096 */
#else
static int pathmax = 0;
#endif

#define SUSV3	200112L

static long posix_version = 0;

/* if PATH_MAX is indeterminate, no guarantee this is adequate */
#define PATH_MAX_GUESS 1024

char *
path_alloc (int *sizep)	/* also return allocated size, if nonnull */
{
	char *ptr;
	int size;

	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);

	if (pathmax == 0)	/* first time through */
	{
		errno = 0;
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
		{
			if (errno == 0)
				pathmax = PATH_MAX_GUESS;	/* indeterminate */
			else
				log_err("pathconf error for _PC_PATH_MAX");
		}
		else
			pathmax++;	/* add one since it's relative to root */
	}
	if (posix_version < SUSV3)
		size = pathmax + 1;
	else
		size = pathmax;

	if ((ptr = malloc(size)) == NULL)
		log_err("malloc error for pathname");

	if (sizep != NULL)
		*sizep = size;
	return ptr;
}

#if 0
int main (void)
{
	int size;
	char *path;

	path = path_alloc(&size);
	printf("path_max is %d, sizeof(path) is %d\n",
		size, sizeof(path));

	printf("sizeof(char)   = %d, sizeof(int)   = %d, sizeof(float)   = %d\n",
			sizeof(char), sizeof(int), sizeof(float));

	printf("sizeof(char *) = %d, sizeof(int *) = %d, sizeof(float *) = %d\n",
			sizeof(char *), sizeof(int *), sizeof(float *));

	free(path);
	return 0;
}
#endif
