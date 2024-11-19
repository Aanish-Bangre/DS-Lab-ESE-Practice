#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

void push(struct Stack *s, char value)
{
    if (s->top == s->size-1)
    {
        printf("Error : Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Error : Stack Underflow");
    }
    else
    {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int precedence(char ch){
    if(ch == '*' || ch =='/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else 
        return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 1;
    else
        return 0;
}

char* reverseString(char* str) {
    int n = strlen(str);
    char* reversed = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        reversed[i] = str[n - i - 1];
    }
    reversed[n] = '\0';
    return reversed;
}

char* infix_to_prefix(char* infix) {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    char *reversedInfix = reverseString(infix);
    int i = 0, j = 0;

    while (reversedInfix[i] != '\0') {
        if (reversedInfix[i] == ')') { // Treat ')' as '('
            push(s, reversedInfix[i]);
        } else if (reversedInfix[i] == '(') { // Treat '(' as ')'
            while (s->top != -1 && s->arr[s->top] != ')') {
                prefix[j++] = pop(s);
            }
            pop(s); // Pop the ')'
        } else if (!isOperator(reversedInfix[i])) {
            prefix[j++] = reversedInfix[i]; // Add operand to result
        } else {
            while (s->top != -1 && precedence(reversedInfix[i]) <= precedence(s->arr[s->top])) {
                prefix[j++] = pop(s);
            }
            push(s, reversedInfix[i]);
        }
        i++;
    }

    while (s->top != -1) {
        prefix[j++] = pop(s);
    }
    prefix[j] = '\0';
    
    char *finalPrefix = reverseString(prefix);\

    return finalPrefix;
}

int main()
{
    char infix[100];
    printf("Enter an infix expression : ");
    scanf("%s", infix);

    printf("%s" , infix_to_prefix(infix));

    return 0;
}