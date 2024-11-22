// 7. Write a program to implement Queue using a circular array. The following operations need to be
// supported:
// a. enqueue
// b. dequeue
// c. isEmpty
// d. isFull
// e. front
// f. rear

#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

void initializeQueue(Queue *q, int size)
{
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->arr = (int *)malloc(size * sizeof(int));
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}
int isFull(Queue *q)
{
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->arr[q->rear] = val;
        q->rear = (q->rear + 1) % q->size;
        printf("Enqueued %d\n", val);
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int val = q->arr[q->front];
        q->front = (q->front + 1) % q->size;
        return val;
    }
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int rear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[(q->rear - 1 + q->size) % q->size];
}

void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initializeQueue(q, 5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    displayQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    displayQueue(q);

    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", rear(q));


    return 0;
}
