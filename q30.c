// 30. Construct a Binary search tree and get the minimum and maximum key in the tree.

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

    if (root->data > value)
        root->left = constructBST(root->left, value);
    else
        root->right = constructBST(root->right, value);

    return root;
}

void inOrder(struct Node *root, int *arr, int *index)
{
    if (root != NULL)
    {
        int i = 0;
        inOrder(root->left, arr, index);
        arr[*index] = root->data;
        (*index)++;
        printf("%d Inserted in the array \n", root->data);
        inOrder(root->right, arr, index);
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

    int size = 6;
    int *arr = (int *)malloc(size * sizeof(int));
    int index = 0; // To keep track of the current position in the array

    // Perform in-order traversal
    inOrder(root, arr, &index);

    int max = arr [0];
    for (int i = 1; i < 6; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    
    printf("Maximum Key : %d \n" , max);
    int min = arr [0];
    for (int i = 1; i < 6; i++)
    {
        if(min > arr[i])
            min = arr[i];
    }
    
    printf("Minimun Key : %d \n" , min);

}