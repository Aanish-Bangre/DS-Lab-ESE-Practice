// 26. Swap nodes of a linked list in pairs
// Example 1:
// input: 1 → 2 → 3 → 4
// output: 2 → 1 → 4 → 3
// Example 2:
// input: 1 → 2 → 3
// output: 2 → 1 → 3

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
    printf("NULL\n");
}

struct Node *initialize(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    return n;
}

struct Node *swap_pairs(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Update the head pointer to the second node
    struct Node *new_head = head->next;
    struct Node *prev = NULL;
    struct Node *current = head;

    while (current != NULL && current->next != NULL)
    {
        struct Node *next_pair = current->next->next;
        struct Node *second = current->next;

        // Swapping nodes
        second->next = current;
        current->next = next_pair;

        if (prev != NULL)
            prev->next = second;

        // Move pointers for the next iteration
        prev = current;
        current = next_pair;
    }

    return new_head;
}

int main()
{
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = initialize(1);
    struct Node *n2 = initialize(2);
    struct Node *n3 = initialize(3);
    struct Node *n4 = initialize(4);
    struct Node *n5 = initialize(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    printf("Original List:\n");
    traverse(head);

    head = swap_pairs(head);
    printf("Swapped List:\n");
    traverse(head);

    return 0;
}
