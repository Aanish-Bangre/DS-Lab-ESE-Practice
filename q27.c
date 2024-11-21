// 27. Construct a binary tree using recursion and traverse it in all possible traversal.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createnode(int data)
{

    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{

    struct Node *head = createnode(7);
    struct Node *n2 = createnode(3);
    struct Node *n3 = createnode(10);
    struct Node *n4 = createnode(9);
    struct Node *n5 = createnode(2);
    struct Node *n6 = createnode(5);
    struct Node *n7 = createnode(12);
    struct Node *n8 = createnode(11);

    head->left = n2;
    head->right = n3;

    n2->left = n5;
    n2->right = n6;

    n3->left = n4;
    n3->right = n7;

    n7->left = n8;

    printf("Inorder : ");
    inOrder(head);
    printf("\n");
    printf("Postorder : ");
    postOrder(head);
    printf("\n");
    printf("Preorder : ");
    preOrder(head);
    printf("\n");
}
