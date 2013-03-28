/*
 * =====================================================================================
 *
 *       Filename:  setugid_demo.c
 *
 *    Description:  setuid() and setgid() demo
 *
 *        Version:  1.0
 *        Created:  03/19/2013 12:06:27 AM
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
#define _USE_GNU
#define _GNU_SOURCE

int main (void)
{
	printf("uid [%d] euid [%d],  gid [%d] egid [%d]\n",
			getuid(), geteuid(), getgid(), getegid());

	uid_t uid = 501;

	if (setuid(uid) < 0)
		log_err("setuid %d", uid);

	gid_t gid = 501;

	if (setgid(gid) < 0)
		log_err("setgid %d", gid);

#ifndef _POSIX_SAVED_IDS
	printf("uid [%d] euid [%d],  gid [%d] egid [%d]\n",
			getuid(), geteuid(), getgid(), getegid());
#else
	uid_t euid, suid;
	gid_t egid, sgid;
	if (getresuid(&uid, &euid, &suid) < 0)
		log_err("getresuid");
	if (getresgid(&gid, &egid, &sgid) < 0)
		log_err("getresgid");

	printf("uid %3d, euid %3d, suid %3d\n"
			"gid %3d, egid %3d, sgid %3d\n",
			uid, euid, suid, gid, egid, sgid);
#endif

	return EXIT_SUCCESS;
}
