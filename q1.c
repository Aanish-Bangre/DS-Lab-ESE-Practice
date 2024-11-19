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

char* infix_to_postfix(char* infix)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char * postfix = (char * )malloc((strlen(infix)+1) * sizeof(char));

    int i = 0 ; // Traversal of infix
    int j = 0 ; // Traversal of postfix
  
    while( infix[i] != '\0' )
    {
        if( !isOperator(infix[i]) ){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if( precedence(infix[i]) >= precedence(s->arr[s->top])){
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(s->top != -1){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[100];
    printf("Enter an infix expression : ");
    scanf("%s", infix);

    printf("%s" , infix_to_postfix(infix));

    return 0;
}