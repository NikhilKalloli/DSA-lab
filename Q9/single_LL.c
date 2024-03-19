#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

struct node *head = NULL;

struct node* createSLL(int);
void insertBeginning();
void insertEnd();
void insertAtPos(int pos);
void display();
void delAtBegining();
void delAtEnd();
void delAtPos(int pos);

int main() {
    createSLL(15);
    insertEnd();
    insertEnd();
    insertEnd();
    insertEnd();
    display();
    delAtPos(3);
    display();
    return 0;
}

struct node* createSLL(int val) {
    node *newNode;
    newNode = ( node *)malloc(sizeof( node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning() {
    int val;
    printf("Enter data at Beginning: ");
    scanf("%d", &val);
    head = createSLL(val);
}

void insertEnd() {
    int val;
    printf("Enter data at End: ");
    scanf("%d", &val);
    node *newNode = createSLL(val);
    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPos(int pos) {

    int val;
    printf("Enter data at position %d: ", pos);
    scanf("%d", &val);
    node *newNode = createSLL(val);

    node *temp=head;
   for(int i=1;i<pos-1;i++){
         temp=temp->next;
   }
    newNode->next=temp->next;
    temp->next=newNode;
}

void delAtBegining() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
}

void delAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    if(head->next==NULL){
        head=NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    node *temp2 = temp->next;
    temp->next=temp2->next;
    free(temp2);

}

void display() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
