#include <stdio.h>
#include <stdlib.h>

int sumAndProduct(int a, int b, int *sum, int *product, int *divisor)
{
    if (sum == NULL || product == NULL || divisor == NULL)
    {
        return 0;
    }

    *divisor = a / b;
    *sum = a + b;
    *product = a * b;
    return 1;
}

int main()
{
    int x = 99, y = 2, sum, product, divisor;
    int status = sumAndProduct(x, y, &sum, &product, &divisor);
    if (status == 0)
    {
        printf("Error");
    }
    else
    {
        printf("The sum is %d and the product is %d and %d", sum, product, divisor);
    }
    return 0;
}