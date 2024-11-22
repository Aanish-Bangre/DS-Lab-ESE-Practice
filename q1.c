#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

void push(struct Stack *s, char value)
{
    if (s->top == s->size - 1)
    {
        printf("Error: Stack Overflow\n");
        exit(1);
    }
    s->top++;
    s->arr[s->top] = value;
}

char pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Error: Stack Underflow\n");
        exit(1);
    }
    return s->arr[s->top--];
}

char peek(struct Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->arr[s->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char *infix_to_postfix(char *infix)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Traversal of infix
    int j = 0; // Traversal of postfix

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')')
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(')
        {
            push(s, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (peek(s) != '(')
            {
                postfix[j++] = pop(s);
            }
            pop(s); // Pop the '('
            i++;
        }
        else
        {
            while (s->top != -1 && precedence(peek(s)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(s);
            }
            push(s, infix[i++]);
        }
    }

    while (s->top != -1)
    {
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';

    // Free allocated memory
    free(s->arr);
    free(s);

    return postfix;
}

int main()
{
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char *postfix = infix_to_postfix(infix);
    printf("Postfix expression: %s\n", postfix);

    free(postfix); // Free memory for postfix
    return 0;
}
