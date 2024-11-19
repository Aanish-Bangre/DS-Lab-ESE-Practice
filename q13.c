// 13.  Given a sorted linked list, delete all duplicates such that each element appears only once.
// For example:
// ● Given 1→1 → 2,    return 1 → 2
// ● Given 1 → 1 → 2 → 3 → 3,  return 1 → 2 → 3

// Given a singly linked list, determine if it's a palindrome. Return 1 or 0 denoting if it's a
// palindrome or not, respectively. For example
// a. List 1 → 2 → 1 is a palindrome.
// b. List 1 → 2 → 3 is not a palindrome

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

struct Node *delete_duplicate(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2;

    while (ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data == ptr2->data)
            {
                ptr1->next = ptr2->next;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
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

int main()
{

    struct Node *head = initialize(1);
    struct Node *n2 = initialize(1);
    struct Node *n3 = initialize(2);
    struct Node *n4 = initialize(3);
    struct Node *n5 = initialize(3);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    traverse(head);
    printf("\n");
    delete_duplicate(head);
    traverse(head);
}