#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head , *tail;

void createDLL();
void insertBeginning();
void insertEnd();
void insertAtPos(int pos);
void display();
void delAtBegining();
void delAtEnd();
void delAtPos(int pos);


int main(){

    createDLL();
    insertEnd();
    insertEnd();
    insertEnd();
    insertEnd();
    display();
    // delAtEnd();
    delAtPos(3);
    display();
    // delAtBegining();
    // display();
    // insertBeginning();
    // insertAtPos(2);
    // display();
    return 0;
}

void createDLL(){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to create List: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head==NULL){
        head=tail=newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail=newNode;
    }

}

void insertBeginning(){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data at Begining: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    // considering there is at least one node before trying this operation.

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertEnd(){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data at end: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    // considering there is at least one node before trying this operation.

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(int pos){
    struct node *newNode;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data at position %d: ", pos);
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    while(pos!=1){
        temp = temp->next;
        pos--;
    }

    
    if(temp->next == NULL){ // if position is last one
        temp->next = newNode;
        newNode->prev = temp;
    }
    else{
        temp2 = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        temp2->prev = newNode;
        newNode->next = temp2;
    }

}


void delAtBegining(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    else if(head==tail){
        head=tail=NULL;
        free(temp);
    }
    else{
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void delAtEnd(){
    struct node *temp;
    temp = tail;

    if(head==NULL){
        printf("List is empty");
        return;
    }
    else if(head==tail){
        head=tail=NULL;
        free(temp);
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}


void delAtPos(int pos){
    struct node *temp = head;
    struct node *temp2 = NULL;
  

    while(pos!=1){
        temp = temp->next;
        pos--;
    }
    
    if(temp->next == NULL){ // if position is last one
        delAtEnd();
    }
    else{
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
    }

}

void display(){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}