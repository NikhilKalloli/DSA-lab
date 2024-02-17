#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void display(){
    struct node *temp;
    temp = top;
    if(top==NULL){
        printf("Stack is empty");
    }
    else{
        printf("Stack is: ");
        while (temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int pop(){
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        int num = top->data;
        top = top->next;
        return num;
    }

}

int main(){
    push(14);
    push(34);
    push(58);
    display();
    pop();
    display();

    return 0;
}
