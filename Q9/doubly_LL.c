#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

struct node *head = NULL;

struct node* createDLL(int val) {
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertBeginning() {
    int val;
    printf("Enter data at Beginning: ");
    scanf("%d", &val);
    node *newNode = createDLL(val);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd() {
    int val;
    printf("Enter data at End: ");
    scanf("%d", &val);
    node *newNode = createDLL(val);
    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPos(int pos) {
    int val;
    printf("Enter data at position %d: ", pos);
    scanf("%d", &val);
    node *newNode = createDLL(val);

    if (pos == 1) {
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void delAtBegining() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void delAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2->next != NULL) {
        temp2->next->prev = temp;
    }
    free(temp2);
}

void display() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    createDLL(15);
    insertEnd();
    insertEnd();
    insertEnd();
    insertEnd();
    display();
    delAtPos(3);
    display();
    return 0;
}
