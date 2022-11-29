#include <stdio.h>
#include <stdlib.h>

int func1(char *string, int *lengthOfString);

int main()
{
    char *st = "Hello World";
    int lengthOfString = func1(st, lengthOfString);

    printf("Lenght of String - %d", lengthOfString);

    return 0;
}
int func1(char *string, int *lengthOfString)
{
    for (int i = 0; i <= lengthOfString; i++)
    {
        while (string[i] != "\0")
        {
            lengthOfString += 1;
            i++;
        }
    }
    return lengthOfString;
}