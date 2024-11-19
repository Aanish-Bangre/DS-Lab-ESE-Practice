// Implement the following operations on doubly linked lists:
// a. Insert (after position)
// b. sort the list
// c. display

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void travers(struct Node *ptr)
{

    printf(" NULL <-> ");
    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL ");
}

struct Node *Insert(struct Node *head)
{
    struct Node *ptr = head;
    int loc;
    printf("Enter position after to insert : ");
    scanf("%d", &loc);

    for (int i = 1; i != loc; i++)
    {
        head = head->next;
    }

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = 6;
    new->next = NULL;
    new->prev = NULL;

    new->next = head->next;
    head->next->prev = new;
    head->next = new;
    new->prev = head;

    head = ptr ;
    return head;
}

void sort_doubly(struct Node *head) {
    if (head == NULL) return;

    int swapped;
    struct Node *ptr1;
    struct Node *ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    struct Node *fifth;
    struct Node *sixth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 6;
    head->next = second;
    head->prev = NULL;

    second->data = 5;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = forth;
    third->prev = second;

    forth->data = 8;
    forth->next = fifth;
    forth->prev = third;

    fifth->data = 7;
    fifth->next = sixth;
    fifth->prev = forth;

    sixth->data = 1;
    sixth->next = NULL;
    sixth->prev = fifth;

    head = Insert(head);

    sort_doubly(head);

    travers(head);

    return 0;
}