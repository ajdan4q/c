/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2013 12:15:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>


typedef struct list {
	int val;
	struct list *next;
} List;

char *insert_sort (char *subarr, int len)
{
	static char sorted[len];

	if (len <= 1)
		return subarr;
	
	char *head = subarr++;
	char *re = insert_sort(subarr, len - 1);
	//1 head, sublist
	//recusive head, sublist (base case len(sublist) == 1)
	
	for (i = 0; i < len; i++)
	{
		if (*head < *(subarr+i))
	}
}
