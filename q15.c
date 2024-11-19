// 15. Write a program to construct a binary search tree and traverse it with all methods that uses
// recursion.

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
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *constructBST(struct Node *root, int value)
{
    if (root == NULL)
        return createnode(value);

    if (root->data < value)
        root->right = constructBST(root->right, value);
    else if (root->data >= value)
        root->left = constructBST(root->left, value);

    return root;
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
    struct Node *root = NULL;
    root = constructBST(root, 4);
    root = constructBST(root, 2);
    root = constructBST(root, 5);
    root = constructBST(root, 9);
    root = constructBST(root, 1);
    root = constructBST(root, 3);

    printf("Inorder : ");
    inOrder(root);
    printf("\n");
    printf("Postorder : ");
    postOrder(root);
    printf("\n");
    printf("Preorder : ");
    preOrder(root);
    printf("\n");
}