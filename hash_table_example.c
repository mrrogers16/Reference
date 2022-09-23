#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TABLE_SIZE 5
#define MAX_NAME 256

typedef struct
{
    char name[MAX_NAME];
    int age;
    // add other stuff later
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

bool hash_table_insert(person *p)
{
    if(p == NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL)
    {
        return false;
    }
    hash_table[index] = p;
    return true;
}

void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

//find an person in the table by their name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE)==0)
    {
        return hash_table[index];
    }
    else
    {
        return NULL;
    }
}

int main()
{
    init_hash_table();
    person Mickey = {.name="Mickey", .age=29};
    person Sara = {.name="Sara", .age=25};

    hash_table_insert(&Mickey);
    hash_table_insert(&Sara);
    print_table();

    person *tmp = hash_table_lookup("Sara");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }

    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Sara => %u\n", hash("Sara"));
    // printf("Mick => %u\n", hash("Mick"));
    // printf("Adrean => %u\n", hash("Adrean"));
    // printf("Dad => %u\n", hash("Dad"));
    // printf("Mom => %u\n", hash("Mom"));
    // printf("Grandma => %u\n", hash("Grandma"));

    return 0;
}