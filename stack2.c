/*
 * =====================================================================================
 *
 *       Filename:  stack2.c
 *
 *    Description:  List-imprementd stack: LIFO (Last in, First out)
 *
 *        Version:  1.0
 *        Created:  03/06/2013 09:01:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "stack2.h"

struct list {
	void *info;
	struct list *next;
};

typedef struct list List;

typedef struct stack {
	int id;
	int size;
	List *list;
} Stack;


static List *headp = NULL;	/* pointer to head of stack */

void stack_create (void *info)
{
	List *list = malloc(sizeof(List));
	list->next = NULL;
	list->info = info;

	headp = list;
}

static int stack_size = 100;

/* init fixed size stack, do not free stack item */
Stack *stack_init (int size)
{
	Stack *stackp = malloc(sizeof(Stack));

	if (size > 0)
		stackp->stack_size = size;

	while (--size)
		stack_push(NULL);

	return stackp;
}

void *stack_pop (void)
{
	List *oldlist = headp;
	void *info = headp->info;

	headp = oldlist->next;
	free(oldlist);
	return info;
}

void stack_push (void *info)
{
	List *newlist = malloc(sizeof(List));
	newlist->info = info;
	newlist->next = headp;

	headp = newlist;
}

static void _stack_destroy(List *head)
{
	if (headp != NULL)
		_stack_destroy(headp->next);

	free(headp->info);
	free(headp);
}

void stack_destroy (void)
{
	_stack_destroy(headp);
}

//bool stack_is_empty (List *list)
int stack_is_empty (void)
{
	if (headp == NULL)
		return 1;
	else
		return 0;
}

int stack_get_size (void)
{
	return 0;
}
