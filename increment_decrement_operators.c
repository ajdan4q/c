#include <stdio.h>

main()
{
    int x, i;
    i=1;
    /* postfix increment increse itself AFTER its value used */
    x = i++; /* increment i AFTER asigned to x. */
    printf("%i\n", x);
    printf("%i\n", i);

    /* prefix increment increment itself BEFORE its value used */
    x = ++i;
    printf("%i\n", x);
    printf("%i\n", i);

    /* In a context where no value is wanted, just increment effect.
     * Does it means no variable assigned by increment operator?
     * e.g.,
     *  if (c == '\n')
     *      nl++
     *
     * Not only value assigned, but also array-subscript
     *      a[i++] = x
     *      NOT eq.
     *      a[++i] = x;
     * */

    return 0;
}
