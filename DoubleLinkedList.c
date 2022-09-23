#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node
{
    int value;
    struct node *next;
    struct node *prev;
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
    result->prev = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    (*head)->prev = node_to_insert;
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

void insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
    new_node->next = node_to_insert_after->next;
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    new_node->prev = node_to_insert_after;
    node_to_insert_after->next = new_node;
}

void remove_node(node_t **head, node_t *node_to_remove)
{
    // if node to remove is head handle
    if (*head == node_to_remove)
    {
        *head = node_to_remove->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        // find the previous node in the list
        node_to_remove->prev->next = node_to_remove->next;
        if (node_to_remove->next != NULL)
        {
            node_to_remove->next->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;
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



    //Create node manually
    // tmp = create_new_node(32);
    // head = tmp;
    // tmp = create_new_node(8);
    // tmp->next = head;
    // head = tmp;
    // tmp = create_new_node(34);
    // tmp->next = head;
    // head = tmp;
    printlist(head);
    remove_node(&head, tmp);
    printlist(head);


    return 0;
}
