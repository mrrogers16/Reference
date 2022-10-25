#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

node_t *create_new_node(int value);
node_t *insert_at_head(node_t **head, node_t *node_to_insert);
void printList(node_t *head);
node_t insert_after_node(node_t *node_to_insert_after, node_t* new_node);

int main()
{
    node_t *tmp;
    node_t *head = NULL;

    for (int i = 0; i < 5; ++i)
    {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }
    printList(head);

    insert_after_node(tmp, create_new_node(33));

    printList(head);

    return 0;
}

node_t insert_after_node(node_t *node_to_insert_after, node_t* new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

void printList(node_t *head)
{
    node_t *temporary = head;
    while(temporary != NULL)
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

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