#include <stdio.h>
#include <stdlib.h>

void fibSeries(int k)
{
    int n1, n2, x;
    int i;
    n1 = 0;
    n2 = 1;
    for (int i = 0; i < k - 2; i++)
    {
        x = n2;
        n2 = n1 + n2;
        n1 = x;
    }
    printf("The %dth number in the fib sequence is: %d\n", k, n2);
}