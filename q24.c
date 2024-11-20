// 24. Add 2 non-negative numbers that have been given as a linked list
// Given two non-empty linked lists representing two non-negative integers. The most
// significant digit comes first and each of their nodes contains a single digit. Add the two
// numbers and return the sum as a linked list. You may assume the two numbers do not
// contain any leading zero, except the number 0 itself.
// Example 1:
// operand_1:   7 → 2 → 3 → 3
// operand_2:       5 → 7 → 4
// result:      7 → 8 → 0 → 7

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

struct Node *reverse(struct Node *ptr)
{
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *current = ptr;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node *add(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = reverse(head1);
    struct Node *ptr2 = reverse(head2);
    struct Node *result = NULL, *tail = NULL;
    int carry = 0;

    // Adding the two numbers
    while (ptr1 != NULL || ptr2 != NULL || carry > 0)
    {
        int sum = carry;
        if (ptr1 != NULL)
        {
            sum += ptr1->data;
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL)
        {
            sum += ptr2->data;
            ptr2 = ptr2->next;
        }

        carry = sum / 10;
        struct Node *newNode = initialize(sum % 10);

        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    // Reverse the result to get the final answer
    result = reverse(result);
    return result;
}

int main()
{

    struct Node *head1 = initialize(5);
    struct Node *n12 = initialize(7);
    struct Node *n13 = initialize(4);

    head1->next = n12;
    n12->next = n13;

    struct Node *head2 = initialize(7);
    struct Node *n22 = initialize(2);
    struct Node *n23 = initialize(3);
    struct Node *n24 = initialize(3);

    head2->next = n22;
    n22->next = n23;
    n23->next = n24;

    printf("Operant 1 : ");
    traverse(head2);
    printf("Operant 2 : ");
    traverse(head1);

    struct Node * result = add(head2, head1);
    printf("Result : ");
    traverse(result);
}