/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  static implement
 *
 *        Version:  1.0
 *        Created:  03/05/2013 08:30:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

typedef struct stack = {
	void *element_type;
	void *freep;
}Stack;

// use macro have a try
#define stack_create(element_type, nsize) \
	(element_type) *freep = malloc(sizeof(element_type) * (nsize));		\
	(element_type) *stack = freep

void stack_create(element_type, int nsize)
{
	// how to specify stack element of type
}

void *pop(void *stack)
{
	--freep;
	return freep;
}

#define push (stack, item)	\
	do { *freep = item; freep++; } while (0)

void push(void *stack, void *item)
{
	freep = item;
	freep++;
}

bool is_empty(void *stack)
{
	if (stack == freep)
		return true;
	return false;
}

void stack_destroy(void *stack)
{
	if (stack != NULL)
		free(stack);
}
