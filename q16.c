// 16. Write  a  program  to  represent  the  given  graph  using  adjacency  matrix  and  implement
// Breadth-First Search Traversal for a given Graph.

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

struct Queue *initialize(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = size;
    q->front = 0;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

void Enqueue(struct Queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = item;
    }
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int val = q->arr[q->front];
        q->front++;
        return val;
    }
}

int isFull(struct Queue *q)
{
    if (q->rear == q->size - 1) // Check if rear has reached the max size
        return 1;
    else
        return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->front > q->rear) // Check if front has passed rear, meaning the queue is empty
        return 1;
    else
        return 0;
}

void print_queue(struct Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("Element: %d\n", q->arr[i]);
    }
}

int main()
{
    struct Queue *q = initialize(100);
    int u;
    int i = 0; // Start Node
    int visited[5] = {0, 0, 0, 0, 0};
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
    };

    printf("%d ", i);
    visited[i] = 1;
    Enqueue(q, i);
    while (!isEmpty(q))
    {
        int node = Dequeue(q);
        for (int j = 0; j < 5; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                Enqueue(q, j);
            }
        }
    }

    return 0;
}
