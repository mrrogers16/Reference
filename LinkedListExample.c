#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

// Prints current linked list
void printlist(node_t *head)
{
    node_t *temporary = head;
    while (temporary != NULL)
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

// Function to create new node and dynamically allocate memory
node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }

    return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t* new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

int main()
{

    node_t *tmp;
    node_t *head = NULL;

    // Print x number of nodes(Order will be reversed)
    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }

    tmp = find_node(head, 2);
    printf("Found node with the value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(43));

    // Create node manually
    // tmp = create_new_node(32);
    // head = tmp;
    // tmp = create_new_node(8);
    // tmp->next = head;
    // head = tmp;
    // tmp = create_new_node(34);
    // tmp->next = head;
    // head = tmp;

    printlist(head);

    return 0;
}
