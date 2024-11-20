// 25. Rotate a Linked List by ‘k’ places.
// Example 1:
// input: 1 → 2 → 3 → 4 → 5 , k = 1
// output: 5 → 1 → 2 → 3 → 4
// Example 2:
// input: 1 → 2 → 3 → 4 → 5 , k = 2
// output: 4 → 5 → 1 → 2 → 3

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n");
}

struct Node *initialize(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    return n;
}

struct Node *rotate(struct Node *head, int k)
{
    struct Node *ptr = head;
    struct Node *tail = NULL;
    struct Node *prev = NULL;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        tail = ptr;
    }

    while (k != 0)
    {
        tail->next = head;
        prev->next = NULL;
        head = tail;
        ptr = head;
        tail = NULL;
        prev = NULL;
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
            tail = ptr;
        }
        k--;
    }
    traverse(head);
}

int main()
{

    struct Node *head = initialize(1);
    struct Node *n2 = initialize(2);
    struct Node *n3 = initialize(3);
    struct Node *n4 = initialize(4);
    struct Node *n5 = initialize(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    traverse(head);

    int k;
    printf("Enter no. times to rotate : ");
    scanf("%d",&k);
    head = rotate(head, k);
}