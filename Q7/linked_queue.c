#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int val){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(front==NULL && rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next = newNode;
        rear=newNode;
    }
}

int dequeue(){
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL){
        printf("Queue is Empty");
    }else{
        int del = front->data;
        front = front->next;
        free(temp);
        return del;
    }
}

void display(){
    struct node *temp;
    if(front==NULL && rear==NULL){
        printf("Queue is Empty");
    }
    else{
        printf("Queue is: ");
        temp=front;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}


int main(){
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