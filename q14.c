// 14. Given  a  linked  list  and  a  value  x,  partition  it  such  that  all  nodes  less  than  x  come  before
// nodes greater than or equal to x. You should preserve the original relative order of the nodes
// in each of the two partitions.
// For example:
// ● Input: 1 → 5 → 3 → 2 → 4 → 2  and x = 3
// ● Output: 1 → 2 → 2 → 3 → 5 → 4

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *initialize(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    return n;
}

void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL");
}

struct Node *operation(struct Node *head, int x)
{
    int *arr_small = (int *)malloc(6 * sizeof(int));
    int *arr_large = (int *)malloc(6 * sizeof(int));

    for (int i = 0; i < 6; i++)
        arr_small[i] = 0;

    for (int i = 0; i < 6; i++)
        arr_large[i] = 0;

    struct Node *ptr = head;
    while (ptr->data != x)
    {
        ptr = ptr->next;
    }
    ptr = head;
    int i = 0; // large elements
    int j = 0; // small elements
    while (ptr != NULL)
    {
        if (ptr->data > x)
        {
            arr_large[i] = ptr->data;
            i++;
        }
        else if (ptr->data < x)
        {
            arr_small[j] = ptr->data;
            j++;
        }
        ptr = ptr->next;
    }

    ptr = head;
    i = 0; // large elements
    j = 0; // small elements

    struct Node *result = NULL, *tail = NULL;

    while (arr_small[j] != 0)
    {
        struct Node *new = initialize(arr_small[j++]);
        // Add the newNode to the result list
        if (result == NULL)
        {
            result = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = new;
        }
    }
    struct Node *new = initialize(x);
    // Add the newNode to the result list
    tail->next = new;
    tail = new;
    while (arr_large[i] != 0)
    {
        struct Node *new = initialize(arr_large[i++]);
        // Add the newNode to the result list
        tail->next = new;
        tail = new;
    }
    return result;
}

int main()
{

    struct Node *head = initialize(1);
    struct Node *n2 = initialize(5);
    struct Node *n3 = initialize(3);
    struct Node *n4 = initialize(2);
    struct Node *n5 = initialize(4);
    struct Node *n6 = initialize(2);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    traverse(head);
    printf("\n");

    head = operation(head, 4);
    traverse(head);
}