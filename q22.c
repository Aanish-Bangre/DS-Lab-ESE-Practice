#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the queue

typedef struct Queue
{
    int items[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }

    int dequeuedValue = q->items[q->front];
    if (q->front == q->rear)
    { // Reset the queue if it becomes empty
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return dequeuedValue;
}

// Function to perform BFS on a graph
void BFS(int graph[7][7], int startNode, int visited[7])
{
    Queue q;
    initializeQueue(&q);

    printf("BFS Traversal: ");
    visited[startNode] = 1;
    enqueue(&q, startNode); // Enqueue the starting node

    while (!isEmpty(&q))
    {
        int currentNode = dequeue(&q);
        printf("%d ", currentNode);

        // Explore all adjacent nodes
        for (int j = 0; j < 7; j++)
        {
            if (graph[currentNode][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    printf("\n");
}

int main()
{
    // Adjacency matrix representing the graph
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    int visited[7] = {0}; // Array to keep track of visited nodes

    BFS(graph, 5, visited); // Perform BFS starting from node 0

    return 0;
}
