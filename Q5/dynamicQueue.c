#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

int *queue;
int front = -1;
int rear = -1;
int capacity;

void enqueue(int val);
int dequeue();
int isEmpty();
void display();

int main() {
    
    queue = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    capacity = INITIAL_CAPACITY;

    
    for (int i = 0; i < 15; i++) {
        enqueue(i);
    }
    display();

    
    printf("The dequeued value is: %d\n", dequeue());

    display();

    
    free(queue);
    return 0;
}

void enqueue(int val) {
    if (rear == capacity - 1) {
        capacity *= 2;
        queue = (int *)realloc(queue, capacity * sizeof(int));
    }
    if (isEmpty()) {
        front = 0;
    }
    queue[++rear] = val;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int val = queue[front++];
    if (front > rear) { // Reset front and rear when queue becomes empty
        front = rear = -1;
    }
    return val;
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("The elements in the queue are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

