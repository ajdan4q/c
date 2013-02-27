/*
 * =====================================================================================
 *
 *       Filename:  print_conf_limit.c
 *
 *    Description:  use sysconf() and pathconf() print all support limits
 *
 *        Version:  1.0
 *        Created:  02/26/2013 07:42:00 PM
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
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define pc(var) pr_pathconf(#var, argv[0], var)
#define nosym(var) puts("no symbol for "#var)

static void pr_sysconf (char *msg, int name);
static void pr_pathconf (char *msg, char *path, int name);

int main ( int argc, char *argv[] )
{
#ifdef _PC_LINK_MAX
	pc(_PC_LINK_MAX);
#else
	nosym(_PC_LINK_MAX);
#endif

#ifdef  _PC_MAX_CANON
	pc(_PC_MAX_CANON);
#else      /* -----  not _PC_MAX_CANON  ----- */
	nosym(_PC_LIN_MAX);
#endif     /* -----  not _PC_MAX_CANON  ----- */

#ifdef  _PC_MAX_INPUT
	pc(_PC_MAX_INPUT);
#else      /* -----  not _PC_MAX_INPUT  ----- */
	nosym(_PC_MAX_INPUT);
#endif     /* -----  not _PC_MAX_INPUT  ----- */

#ifdef  _PC_NAME_MAX
	pc(_PC_NAME_MAX);
#else      /* -----  not _PC_NAME_MAX  ----- */
	nosym(_PC_NAME_MAX);
#endif     /* -----  not _PC_NAME_MAX  ----- */

#ifdef  _PC_PATH_MAX
	pc(_PC_PATH_MAX);
#else      /* -----  not _PC_PATH_MAX  ----- */
	nosym(_PC_PATH_MAX);
#endif     /* -----  not _PC_PATH_MAX  ----- */

#ifdef  _PC_PIPE_BUF
	pc(_PC_PIPE_BUF);
#else      /* -----  not _PC_PIPE_BUF  ----- */
	nosym(_PC_PIPE_BUF);
#endif     /* -----  not _PC_PIPE_BUF  ----- */

#ifdef  _PC_CHOWN_RESTRICTED
	pc(_PC_CHOWN_RESTRICTED);
#else      /* -----  not _PC_CHOWN_RESTRICTED  ----- */
	nosym(_PC_CHOWN_RESTRICTED);
#endif     /* -----  not _PC_CHOWN_RESTRICTED  ----- */

#ifdef  _PC_NO_TRUNC
	pc(_PC_NO_TRUNC);
#else      /* -----  not _PC_NO_TRUNC  ----- */
	nosym(_PC_NO_TRUNC);
#endif     /* -----  not _PC_NO_TRUNC  ----- */

#ifdef  _PC_VDISABLE
	pc(_PC_VDISABLE);
#else      /* -----  not _PC_VDISABLE  ----- */
	nosym(_PC_VDISABLE);
#endif     /* -----  not _PC_VDISABLE  ----- */

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

static void pr_sysconf (char *msg, int name)
{
	long val;
	if ((val = sysconf(name)) == -1)
	{
		perror(msg);
	} 
	else 
	{
		printf("%s %li\n",  msg, val);
		if (errno != 0) perror(msg);
	}
}

static void pr_pathconf (char *msg, char *path, int name)
{
	long val;

	if ((val = pathconf(path, name)) == -1)
	{
		if (errno != 0)
			perror(msg);
		else
			printf("%s %s do not have a limit", msg, path);
	}
	else 
	{
		printf("%s %s %li\n", msg, path, val);
		if (errno != 0) perror(msg);
	}
}
