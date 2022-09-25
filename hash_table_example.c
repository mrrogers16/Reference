#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TABLE_SIZE 10
#define MAX_NAME 256
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

typedef struct
{
    char name[MAX_NAME];
    int age;
    struct person *next;
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
    if (p == NULL)
        return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

void print_table()
{
    printf("Start\n");
    
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else if(hash_table[i] == DELETED_NODE)
        {
            printf("\t%i\t---<deleted>\n", i);
            
        }
        else
        {    
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

// find an person in the table by their name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + 1) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false; // Not here
        }
        if (hash_table[try] == DELETED_NODE)
        {
            continue;
        }
        if (strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}
person *hash_table_delete(char *name)
{

    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + 1) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE)
        {
            continue;
        }
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main()
{
    init_hash_table();
    person Mickey = {.name = "Mickey", .age = 29};
    person Sara = {.name = "Sara", .age = 25};
    person Karla = {.name = "Karla", .age = 57};
    person Dick = {.name = "Dick", .age = 77};
    person Adrean = {.name = "Adrean", .age = 23};
    person Grandma = {.name = "Grandma", .age = 88};
   
    hash_table_insert(&Mickey);
    hash_table_insert(&Sara);
    hash_table_insert(&Karla);
    hash_table_insert(&Dick);
    hash_table_insert(&Adrean);
    hash_table_insert(&Grandma);
   
    person *tmp = hash_table_lookup("Sara");
    if (tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }
    printf("Has been deleted %s",hash_table_delete("Mickey"));
    print_table();
    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Sara => %u\n", hash("Sara"));
    // printf("Mick => %u\n", hash("Mick"));
    // printf("Adrean => %u\n", hash("Adrean"));
    // printf("Dad => %u\n", hash("Dad"));
    // printf("Mom => %u\n", hash("Mom"));
    // printf("Grandma => %u\n", hash("Grandma"));

    return 0;
}