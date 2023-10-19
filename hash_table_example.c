
#include <stdlib.h>
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
    {
        return false;
    }
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
        else if (hash_table[i] == DELETED_NODE)
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
    person bill = {.name = "bill", .age = 29};
    person bert = {.name = "bert", .age = 25};
    person barthert = {.name = "barthert", .age = 57};
    person bobbert = {.name = "bobbert", .age = 77};
    person bartrom = {.name = "bartrom", .age = 23};
    person kyle = {.name = "kyle", .age = 88};

    hash_table_insert(&bill);
    hash_table_insert(&bert);
    hash_table_insert(&barthert);
    hash_table_insert(&bobbert);
    hash_table_insert(&bartrom);
    hash_table_insert(&kyle);

    person *tmp = hash_table_lookup("bill");
    if (tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }
    printf("Has been deleted %s", hash_table_delete("kyle"));
    print_table();

    return 0;
}