/*
 * =====================================================================================
 *
 *       Filename:  stack2.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/2013 09:47:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ajdan4q (), ajdan4q@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _stack2_h
#define _stack2_h

void stack_create (void *info);
void stack_init (int size);
void *stack_pop (void);
void stack_push (void *info);
void stack_destroy (void);
int stack_is_empty (void);
int stack_get_size (void);

#endif
