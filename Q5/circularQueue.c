#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull();
int isEmpty();
void enqueue(int value);
int dequeue();
void display();

int main() {
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("Initial Queue: ");
    display();

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    printf("Queue after dequeue: ");
    display();

   
    enqueue(6);
    enqueue(7);

    printf("Queue after enqueue: ");
    display();

    return 0;
}


int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1 && rear == -1) { // empty
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int dequeued = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return dequeued;
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } 
    printf("\n");
}
