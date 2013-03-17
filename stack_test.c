/*
 * =====================================================================================
 *
 *       Filename:  stack_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/2013 09:19:50 PM
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
#include "stack2.h"

typedef struct info {
	int id;
	char *name;
} Info;

int main (void)
{
	Info *info = malloc(sizeof(Info));

	info->id = 1;
	info->name = "ajdan4q";

	stack_create(info);

	Info *info2 = malloc(sizeof(Info));

	info2->id = 2;
	info2->name = "msking";

	stack_push(info2);

	if (! stack_is_empty())
		printf("stack is not empty\n");

	Info *item = stack_pop();
	printf("first pop %d : %s\n",
			item->id, item->name);

	Info *item2 = stack_pop();
	printf("second pop %d : %s\n",
			item2->id, item2->name);

	free(item);
	free(item2);

	if (stack_is_empty())
		printf("stack is empty\n");

	int i;
	for (i = 0; i < 10; i++)
		stack_push((int *)i);

	while (! stack_is_empty())
		printf("%d\n", (int) stack_pop());

	return EXIT_SUCCESS;
}
