#include <stdio.h>

int count_bit_1 (int n)
{
	// from right to left 
	int c = 0;
	int i;
	for (i = 0; i < 32; ++i)
	{
		if (n & (1 << i))
			c++;
	}
	return c;
}

int count_bit_2 (int n)
{
	int c = 0;
	for (; n; n >>= 1) // right shift operand 1 bit a time
		if (n & 1)
			c++;
	return c;
}

int main(void)
{
    /* shifts left the values of 5 by two positions,
     * right padding vacated bits with zero
     * */
    printf("%i\n", 5 << 2);

    /* shifts right the values of 5 by two positions,
     * left padding vacated bits with zero
     * */
    printf("%i\n", 5 >> 2);

    /* shift left 1 bit -> n * 2
     * shift right 1 bit -> n / 2
     */
	int i = 5 << 2;
	printf("count bit of 5: %i\n", count_bit_1(i));
	printf("count bit of 5: %i\n", count_bit_2(i));

	return 0;
}
