#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
// Confirm if we need to implement Stack using Structure or dynamic array.



int stack[MAX]; 
int top = -1;

void push(int);
int pop();
int isEmpty();
void display();



int main()
{
    for (int i = 0; i < 4; i++)
    {
        push(i);
    }
    display();

    printf("The deletd value is: %d\n", pop());

    display();
    return 0;
}

void push(int  val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = val;
}

int pop()
{
    int val;
    if (top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    val = stack[top];
    top-- ;
    return val;
}

void display()
{
    int i = top;
    printf("The values in stack are: ");
    while (i >= 0)
    {
        printf("%d  ", stack[i--]);
    }
    printf("\n");
}

