#include<stdio.h>
#include<stdlib.h>

#define INITIAL_SIZE 5

int front = -1;
int rear = -1;
int* Queue = NULL;
int size = 0;

void enqueue(int val);
int dequeue();
void display();

int main() {
    enqueue(3);
    enqueue(24);
    enqueue(11);
    enqueue(7);
    enqueue(63);
    
    enqueue(89);
    enqueue(45);

    display();

    dequeue();
    dequeue();
    dequeue();

    display();
    
    enqueue(111);
    enqueue(222);
    enqueue(333);

    display();

    free(Queue); 

    return 0;
}

void enqueue(int val) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        size = INITIAL_SIZE;
        Queue = (int*)malloc(size * sizeof(int));
        if (Queue == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        Queue[rear] = val;
    } else if ((rear + 1) % size == front) {
        printf("Queue is full\n");
      
        size *= 2;
        Queue = (int*)realloc(Queue, size * sizeof(int));
        if (Queue == NULL) {
            printf("Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
        rear = (rear + 1) % size;
        Queue[rear] = val;
    } else {
        rear = (rear + 1) % size;
        Queue[rear] = val;
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        int del = Queue[front];
        front = -1;
        rear = -1;
        free(Queue);
        return del;
    } else {
        int del = Queue[front];
        front = (front + 1) % size;
        return del;
    }
}

void display() {
    int i = front;
    printf("Queue is: ");
    while (i != rear) {
        printf("%d ", Queue[i]);
        i = (i + 1) % size;
    }
    printf("%d ", Queue[rear]);
    printf("\n");
}


