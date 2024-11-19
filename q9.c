// Implement univariate Polynomial addition using linked lists. A univariate polynomial 
// should be represented in the decreasing order of its coefficient. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff; // Coefficient of the term
    int deg;   // Degree of the term
    struct Node *next;
};

// Function to create a new node
struct Node *initialize(int deg, int coeff)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->coeff = coeff;
    n->deg = deg;
    n->next = NULL;
    return n;
}

// Function to add two polynomials
struct Node *poly_sum(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL, *tail = NULL;

    while (poly1 != NULL || poly2 != NULL)
    {
        struct Node *newNode;
        if (poly1 != NULL && poly2 != NULL && poly1->deg == poly2->deg)
        {
            // Same degree terms: Add coefficients
            newNode = initialize(poly1->deg, poly1->coeff + poly2->coeff);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly2 == NULL || (poly1 != NULL && poly1->deg > poly2->deg))
        {
            // poly1 term has a higher degree or poly2 is exhausted
            newNode = initialize(poly1->deg, poly1->coeff);
            poly1 = poly1->next;
        }
        else
        {
            // poly2 term has a higher degree
            newNode = initialize(poly2->deg, poly2->coeff);
            poly2 = poly2->next;
        }

        // Add the newNode to the result list
        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}

// Function to traverse and print a polynomial
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->deg);
        if (ptr->next != NULL)
            printf(" + ");
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    // Create the first polynomial: 1x^3 + 2x^2 + 4x^1 + 1x^0
    struct Node *poly1 = initialize(3, 1);
    poly1->next = initialize(2, 2);
    poly1->next->next = initialize(1, 4);
    poly1->next->next->next = initialize(0, 1);

    // Create the second polynomial: 3x^2 + 2x^1 + 4x^0
    struct Node *poly2 = initialize(2, 3);
    poly2->next = initialize(1, 2);
    poly2->next->next = initialize(0, 4);

    // Compute the sum
    struct Node *result = poly_sum(poly1, poly2);

    // Display the result
    printf("Polynomial 1: ");
    traverse(poly1);

    printf("Polynomial 2: ");
    traverse(poly2);

    printf("Sum: ");
    traverse(result);

    return 0;
}
