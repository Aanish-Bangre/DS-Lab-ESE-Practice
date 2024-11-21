// 33. Construct a binary search tree and get the balance factor of the given node.


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

int treeHeight(struct Node *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int balncefactor(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return leftHeight - rightHeight;
}

int main()
{
    // Construct the binary tree:
    //       7
    //     /   \
    //    3     10
    //   / \   /  \
    //  2   5 9   12
    //           /
    //          11
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

    printf("Balance Factor of Root Node (7): %d\n", balncefactor(head));
}
