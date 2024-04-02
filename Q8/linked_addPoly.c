#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} node;

node* create(int coef, int exp) {
    node* p = (node*)malloc(sizeof(node));
    p->coef = coef;
    p->exp = exp;
    p->next = NULL;
    return p;
}

node* push(node *head, int coef, int exp) {
    node *temp = create(coef, exp);
    if (head == NULL)
        return temp;
    else {
        temp->next = head;
        return temp;
    }
}

node* solve(node* p1, node* p2, node* ans) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            ans = push(ans, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else if (p1->exp < p2->exp) {
            ans = push(ans, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else {
            ans = push(ans, p1->coef + p2->coef, p1->exp);
            p1 = p1->next; 
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        ans = push(ans, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        ans = push(ans, p2->coef, p2->exp);
        p2 = p2->next;
    }
    return ans;
}

node* read(node* p, int n) {
    printf("Enter coeff and expo");
    for (int i = 0; i < n; i++) {
        int coef, exp;
        scanf("%d%d", &coef, &exp);
        p = push(p, coef, exp);
    }
    return p;
}

void display(node* p) {
    node* temp = p;
    if (temp == NULL)
        return;
    
    while (temp != NULL) {
        printf("%dx^%d+", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf("0\n");
}

int main() {
    node *p1 = NULL;
    node *p2 = NULL;
    node* ans = NULL;
    
    int n = 3;
    int m = 3;
    
    p1 = read(p1, n);
    p2 = read(p2, m);
    display(p1);
    display(p2);
    
    ans = solve(p1, p2, ans);
    display(ans);
    
    return 0;
}