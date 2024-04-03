#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int val)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        int del = front->data;
        front = front->next;
        free(temp);
        return del;
    }
}

void display()
{
    node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue is: ");
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    enqueue(45);
    enqueue(23);
    enqueue(18);
    display();
    dequeue();
    display();
    enqueue(78);
    display();
    return 0;
}