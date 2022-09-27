
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024

typedef struct simLog
{
    unsigned int start_time;
    char *msg[512];
    unsigned int msg_id;
    unsigned int start_node;
    unsigned int end_node;
    int *simList;
} Log;

int check_columns(char buffer[]);
void build_sim(Log *simList, char buffer[], FILE *sim);
void stripComment(char buffer[]);
int checkString(char buffer[], int size);

int main()
{
    FILE *sim = NULL;
    char buffer[BUFF_SIZE];
    Log simList[100];
    sim = fopen("simple.sim", "r");
    build_sim(simList, buffer, sim);
    fclose(sim);
}



int check_columns(char buffer[])
{
    size_t len = strlen(buffer);
    int i;
    int columns = 0;
    for (i = 0; i < len; i++)
    {
        if (buffer[i] == ',')
        {
            columns += 1;
        }
        else
        {
            continue;
        }
    }
    return columns;
}

void stripComment(char buffer[])
{
    char COMMENT_MARKER = '#';
    char *comment = strchr(buffer, COMMENT_MARKER);

    if (comment != NULL)
    {
        size_t len = strlen(comment);
        memset(comment, '\0', len);
    }
}
int checkString(char buffer[], int size)
{
    int buffLen = (int)strlen(buffer) - size;

    if (buffLen <= 0)
    {
        buffer = 0;
    }
    else
    {
        printf("Your input is %d over the maximum size of %d\n", buffLen, size);
    }
    return buffLen;
}