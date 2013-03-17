/*
 * =====================================================================================
 *
 *       Filename:  struct_with_function.c
 *
 *    Description:  use struct as function arguments and return value
 *
 *        Version:  1.0
 *        Created:  03/04/2013 06:17:20 AM
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

struct name {
	char *firstname;
	char *lastname;		/* without semicolon, will warning */
};

struct name pass_and_return_struct (struct name aname);
void pass_struct_pointer (struct name *person);

int main (void)
{
	// another way to init struct ?
	struct name msking;
	msking.firstname = "king";
	msking.lastname = "ms";

	struct name ajdan4q = {
		.firstname = "ajd",
		.lastname = "4q",
	};

	printf("before swaped firstname: %s, lastname: %s\n",
			msking.firstname, msking.lastname);

	struct name ret = pass_and_return_struct(msking);

	printf("after swaped firstname: %s, lastname: %s\n",
			ret.firstname, ret.lastname);

	printf("before swaped firstname: %s, lastname: %s\n",
			ajdan4q.firstname, ajdan4q.lastname);

	pass_struct_pointer(&ajdan4q);

	printf("after swaped firstname: %s, lastname: %s\n",
			ajdan4q.firstname, ajdan4q.lastname);

	return EXIT_SUCCESS;
}

struct name pass_and_return_struct (struct name aname)
{
	/* swap firstname and lastname */
	struct name temp = {
		.firstname = aname.lastname,
		.lastname = aname.firstname,
	};
	return temp;
}

/* pointer version */
void pass_struct_pointer (struct name *person)
{
	// swap firstname and lastname

	char *lname = person->lastname;
	person->lastname = person->firstname;
	person->firstname = lname;
}
