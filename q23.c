// 23. Implement  the  Max  Heap  tree  and  sort  the  elements.  The  following  operations  should  be 
// supported: 
// a. heapify 
// b. extractMax (Deleting the max element)  
// c. heapsort 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node * right;
};

struct Node* createnode(int data){

    struct Node *n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n -> data = data;
    n ->left = NULL ;
    n ->right = NULL ;
    return n ;
}


int main(){

    struct Node *head = createnode(7);
    struct Node *n2 = createnode(3);
    struct Node *n3 = createnode(10);
    struct Node *n4 = createnode(9);
    struct Node *n5 = createnode(2);
    struct Node *n6 = createnode(5);
    struct Node *n7 = createnode(12);
    struct Node *n8 = createnode(11);

    head -> left = n2 ;
    head -> right = n3 ;

    n2 -> left = n5 ;
    n2 -> right = n6 ;
    n3 -> left = n4 ;
    n3 ->  right = n7 ;

    n7 -> left = n8 ;  
}
