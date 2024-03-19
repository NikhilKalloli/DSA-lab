#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


char stack[MAX]; 
char infix[MAX];
char postfix[MAX];

int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);

int main()
{
    printf("Enter the infix expression: ");
    gets(infix);

    inToPost();
    print();
    return 0;
}

void inToPost()
{
    int j = 0;
    char symbol;
    char next;

    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default: // if symbol is an operand
                postfix[j++] = symbol;
            }
        }
    }

    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int space(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '*':
    case '/':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

void print()
{
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}


int post_eval()
{
    int a, b;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] > '0' && postfix[i] < '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            }
        }
    }
    return pop();
}