#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the queue structure
typedef struct {
    int *data;
    int front, rear, size, capacity;
} Queue;

// Function to initialize a queue
Queue* createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
bool isFull(Queue *queue) {
    return queue->size == queue->capacity;
}

// Function to enqueue an element
void enqueue(Queue *queue, int x) {
    if (!isFull(queue)) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->data[queue->rear] = x;
        queue->size++;
    }
}

// Function to dequeue an element
int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        int item = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return item;
    }
    return -1;
}

// Function to get the front element of the queue
int front(Queue *queue) {
    return queue->data[queue->front];
}

// Define the stack structure using two queues
typedef struct {
    Queue *queue1;
    Queue *queue2;
} MyStack;

// Function to initialize the stack
MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue1 = createQueue(100);  // Assuming max size of 100
    stack->queue2 = createQueue(100);
    return stack;
}

// Function to push an element onto the stack
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->queue2, x);
    while (!isEmpty(obj->queue1)) {
        enqueue(obj->queue2, dequeue(obj->queue1));
    }

    // Swap the queues
    Queue *temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
}

// Function to pop an element from the stack
int myStackPop(MyStack* obj) {
    return dequeue(obj->queue1);
}

// Function to get the top element
int myStackTop(MyStack* obj) {
    return front(obj->queue1);
}

// Function to check if the stack is empty
bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->queue1);
}

// Function to free the allocated memory
void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    free(obj->queue1);
    free(obj->queue2->data);
    free(obj->queue2);
    free(obj);
}

