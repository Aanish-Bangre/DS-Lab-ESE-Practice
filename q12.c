// 12. Implement the following operations on doubly linked lists:
// a. Insert (end)
// b. concatenate two lists
// c. display

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *initialize(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

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

struct Node *Insert_end(struct Node *head, int new_data)
{
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    struct Node *new = initialize(new_data);
    ptr->next = new;
    new->prev = ptr;

    return head;
}

struct Node *concat(struct Node *n1, struct Node *n2)
{

    struct Node *head = n1;
    while (n1->next != NULL)
    {
        n1 = n1->next;
    }

    n1->next = n2;
    n2->prev = n1;

    return head;
}

int main()
{

    struct Node *head1 = initialize(6);
    struct Node *second1 = initialize(5);
    struct Node *third1 = initialize(3);
    struct Node *forth1 = initialize(8);
    struct Node *fifth1 = initialize(7);
    struct Node *sixth1 = initialize(1);

    head1->next = second1;
    head1->prev = NULL;

    second1->next = third1;
    second1->prev = head1;

    third1->next = forth1;
    third1->prev = second1;

    forth1->next = fifth1;
    forth1->prev = third1;

    fifth1->next = sixth1;
    fifth1->prev = forth1;

    sixth1->next = NULL;
    sixth1->prev = fifth1;

    struct Node *head2 = initialize(3);
    struct Node *second2 = initialize(6);
    struct Node *third2 = initialize(1);
    struct Node *forth2 = initialize(9);
    struct Node *fifth2 = initialize(4);
    struct Node *sixth2 = initialize(8);

    head2->next = second2;
    head2->prev = NULL;

    second2->next = third2;
    second2->prev = head2;

    third2->next = forth2;
    third2->prev = second2;

    forth2->next = fifth2;
    forth2->prev = third2;

    fifth2->next = sixth2;
    fifth2->prev = forth2;

    sixth2->next = NULL;
    sixth2->prev = fifth2;

    // Insert_end(head1, 9);

    concat(head1, head2);

    travers(head1);

    return 0;
}