#include <stdio.h>

int main (void)
{
	int *intp = (int *)1; /* intp content is 0x1 */
	void *vp = (void *)2;

	intp = vp;
	//vp = intp; /* vp -> intp, vp -> vp */

	/* diff pointer type want to explit type convert */
	int *p1;
	float *p2 = (float *) 0x1000;
	p1 = (int *) p2;
	printf("p1 %%p %p %%x %#x\n", p1, (int) p1);

	printf("intp value %d\n", (int) intp);
	printf("intp %p\n", intp);
	/* deref 'void *voidp' use (type) voidp 
	 * '*voidp' will error, voidp uninited
	 * */ 
	printf("vp value %d\n", (int) vp);
	printf("vp %p\n", vp);
	return 0;
}
