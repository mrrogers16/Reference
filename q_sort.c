#include <stdio.h>
#include <stdlib.h>

int compare(const void *x_void, const void *y_void);

int main()
{
    int a[] = {8, 7, 2, 4, 22, 3, 5, 1, 9, 0};
    int length = 10;
    qsort(a, length, sizeof(int), compare);

    for(int i = 0; i < length; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

        return 0;
}

int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y;
}