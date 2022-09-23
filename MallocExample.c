#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *p, n;
    printf("Enter a value: \n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    printf("Entering integers: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", p + i);
    }
    free(p);
    return 0;
}