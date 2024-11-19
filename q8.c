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

int *save(struct Node *ptr, int *size)
{
    // Count the number of nodes
    int cnt = 0;
    struct Node *temp = ptr;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    *size = cnt;                                 // Update size
    int *arr = (int *)malloc(cnt * sizeof(int)); // Allocate memory for the array
    int i = 0;

    // Store data in the array
    while (ptr != NULL)
    {
        arr[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }

    return arr;
}

int isPalindrom(struct Node *ptr)
{
    int size = 0;
    int *arr = save(ptr, &size);

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

    int size2 = 0;
    int *arr2 = save(prev, &size2);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr2[i])
            return 0;
        else
            return 1;
    }
}

int main()
{

    struct Node *head = initialize(2);
    struct Node *n2 = initialize(3);
    struct Node *n3 = initialize(4);

    head->next = n2;
    n2->next = n3;

    if(isPalindrom(head))
        printf("Palindrom Confirmed");
    else
        printf("Palindrom Not Confirmed");
}