#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} node;

void push(node **head, int coeff, int exp)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

void read(node **p)
{
    printf("Enter total number of terms: ");
    int terms;
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++)
    {
        int coeff, exp;
        scanf("%d", &coeff);
        scanf("%d", &exp);
        push(p, coeff, exp);
    }
}

void solve(node *p1, node *p2, node **ans)
{
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            push(ans, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            push(ans, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            push(ans, (p2->coeff + p1->coeff), p2->exp);
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    while (p1 != NULL)
    {
        push(ans, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        push(ans, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

void display(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        printf("%dx^%d+", curr->coeff, curr->exp);
        curr = curr->next;
    }
    printf("0\n");
}

int main()
{
    node *p1 = NULL;
    node *p2 = NULL;
    node *ans = NULL;

    read(&p1);
    read(&p2);
    display(p1);
    display(p2);

    solve(p1, p2, &ans);
    display(ans);


    return 0;
}
