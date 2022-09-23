#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *fIn;
    fIn = fopen(argv[3], "r");

    int i = 0;

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s \n", i, argv[i]);
    }

    int result = 1;

    for (i = 1; i < argc; i++)
    {
        int x = strtol(argv[i], NULL, 10);
        result = result * x;
    }
    printf("Result is %d\n", result);

    return 0;
}