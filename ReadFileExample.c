// Read all text from a file example
#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[255];

    fp = fopen("F:\\PythonProjects\\C\\text.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return (-1);
    }
    while (fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }

    return 0;
}