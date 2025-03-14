#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the stack structure
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Function to initialize a stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int x) {
    stack->data[++stack->top] = x;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    return stack->data[stack->top--];
}

// Function to get the top element of the stack
int peek(Stack *stack) {
    return stack->data[stack->top];
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Define the queue structure using two stacks
typedef struct {
    Stack *stack1;
    Stack *stack2;
} MyQueue;

// Function to initialize the queue
MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack(100);  // Assuming a maximum size of 100
    queue->stack2 = createStack(100);
    return queue;
}

// Function to push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stack1, x);
}

// Function to pop an element from the queue
int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            push(obj->stack2, pop(obj->stack1));
        }
    }
    return pop(obj->stack2);
}

// Function to get the front element
int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            push(obj->stack2, pop(obj->stack1));
        }
    }
    return peek(obj->stack2);
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1) && isEmpty(obj->stack2);
}

// Function to free the allocated memory
void myQueueFree(MyQueue* obj) {
    free(obj->stack1->data);
    free(obj->stack1);
    free(obj->stack2->data);
    free(obj->stack2);
    free(obj);
}
