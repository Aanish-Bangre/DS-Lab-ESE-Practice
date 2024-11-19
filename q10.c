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

// Function to multiply two polynomials
struct Node *poly_multi(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;

    struct Node *ptr1 = poly1;
    while (ptr1 != NULL)
    {
        struct Node *ptr2 = poly2;
        while (ptr2 != NULL)
        {
            // Calculate the degree and coefficient for the product term
            int new_deg = ptr1->deg + ptr2->deg;
            int new_coeff = ptr1->coeff * ptr2->coeff;

            // Add the product term to the result
            if (result == NULL)
            {
                // First term in the result
                result = initialize(new_deg, new_coeff);
            }
            else
            {
                // Insert the term in the correct position (sorted by degree)
                struct Node *current = result, *prev = NULL;
                while (current != NULL && current->deg > new_deg)
                {
                    prev = current;
                    current = current->next;
                }

                if (current != NULL && current->deg == new_deg)
                {
                    // If degree matches, add the coefficients
                    current->coeff += new_coeff;
                }
                else
                {
                    // Insert the new term
                    struct Node *newNode = initialize(new_deg, new_coeff);
                    if (prev == NULL)
                    {
                        // Insert at the beginning
                        newNode->next = result;
                        result = newNode;
                    }
                    else
                    {
                        // Insert in the middle or at the end
                        newNode->next = current;
                        prev->next = newNode;
                    }
                }
            }

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
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
    // Create the first polynomial: 3x^2 + 2x^1 + 3x^0
    struct Node *poly1 = initialize(2, 3);
    poly1->next = initialize(1, 2);
    poly1->next->next = initialize(0, 3);

    // Create the second polynomial: 2x^1 + 3x^0
    struct Node *poly2 = initialize(1, 2);
    poly2->next = initialize(0, 3);

    // Multiply the polynomials
    struct Node *result = poly_multi(poly1, poly2);

    // Display the polynomials and the result
    printf("Polynomial 1: ");
    traverse(poly1);

    printf("Polynomial 2: ");
    traverse(poly2);

    printf("Product: ");
    traverse(result);

    return 0;
}
