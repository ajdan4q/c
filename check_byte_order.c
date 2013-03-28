/*
 * =====================================================================================
 *
 *       Filename:  check_byte_order.c
 *
 *    Description:  check system whether big-endian or little-endian
 *
 *        Version:  1.0
 *        Created:  03/26/2013 08:51:14 PM
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
#include <inttypes.h>

int main (void)
{
	uint32_t i;
	unsigned char * cp;

	// big-endian, high bit put front (left), at low memory address
	// little-endian, high bit put back (right), at high memory address
	//
	// given '0x04030201'
	//
	// memory low address -> high address
	// 04 03 02 01	(big-endian)
	// 01 02 03 04	(little-endian)

	i = 0x04030201;
	cp = (unsigned char *) &i;

//	printf("i %x\n", i);
//	printf("&i %p\n", &i);
//	printf("cp %p\n", cp);

	if (*cp == 1)
		printf("little-endian\n");
	else if (*cp == 4)
		printf("big-endian\n");
	else
		printf("who knows?\n");

	exit(EXIT_SUCCESS);
}
