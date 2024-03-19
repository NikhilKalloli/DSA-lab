#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int *stack;
int top = -1;
int capacity;

void push(int val);
int pop();
int isEmpty();
void display();

int main() {
    // Initialize the stack with initial capacity
    stack = (int *)malloc(SIZE * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    capacity = SIZE;

    // Push elements onto the stack
    for (int i = 0; i < 15; i++) {
        push(i);
    }
    display();

    // Pop an element from the stack
    printf("The deleted value is: %d\n", pop());

    display();

    // Free dynamically allocated memory
    free(stack);
    return 0;
}

void push(int val) {
    if (top == capacity - 1) {
        capacity *= 2;
        stack = (int *)realloc(stack, capacity * sizeof(int));
    }
    stack[++top] = val;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void display() {
    printf("The values in stack are: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

