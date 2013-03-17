/*
 * =====================================================================================
 *
 *       Filename:  get_ip.c
 *
 *    Description:  getaddrinfo() usage
 *
 *        Version:  1.0
 *        Created:  03/09/2013 08:52:26 PM
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
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int argc, char *argv[])
{
	int ret;
	struct addrinfo *res, *rp,  hint;

	memset(&hint, 0, sizeof(struct addrinfo));

	hint.ai_family = AF_INET;

	ret = getaddrinfo(NULL, "80", &hint, &res);

	if (ret != 0)
		perror("getaddrinfo");

	for (rp = res; rp != NULL; rp = rp->ai_next)
	{
		struct sockaddr_in *sai = (struct sockaddr_in *) rp->ai_addr;
		printf("%s\n", inet_ntoa(sai->sin_addr));
	}

	return EXIT_SUCCESS;
}
