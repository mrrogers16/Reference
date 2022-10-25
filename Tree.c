#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct treenode
{
    int value;
    struct treenode *right;
    struct treenode *left;
} treenode;

treenode *createnode(int value)
{
    treenode *result = malloc(sizeof(treenode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTab(int numTabs)
{
    for (int i = 0; i < numTabs; i++)
    {
        printf("\t");
    }
}

void printTree(treenode *root)
{
    printTree_rec(root, 0);
}

void printTree_rec(treenode *root, int level)
{
    if (root == NULL)
    {
        printTab(level);
        printf("---empty---");
        return;
    }
    printTab(level);
    printf("Value - %d\n", root->value);

    printTab(level);
    printf("left\n");
    printTree_rec(root->left, level + 1);

    printTab(level);
    printf("right\n");
    printTree_rec(root->right, level + 1);

    printTab(level);
    printf("Done\n");
}

int main()
{
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n4->right = n5;

    printTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}