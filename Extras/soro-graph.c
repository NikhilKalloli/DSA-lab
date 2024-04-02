#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

#define max 100

typedef struct Graph
{
    int maxnode;
    node *adjmat[max];
} graph;

node *createnode(int value)
{
    node *p = (node *)malloc(sizeof(node));
    p->value = value;
    p->next = NULL;
    return p;
}

graph *creategraph(int num)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->maxnode = num;

    for (int i = 0; i < g->maxnode; i++)
    {
        g->adjmat[i] = NULL;
    }
    return g;
}

node *add(node *head, node *temp)
{
    if (head == NULL)
        return temp;
    node *dummy = head;
    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }
    dummy->next = temp;
    return head;
}

void addedge(graph *g, int src, int des)
{
    node *temp = createnode(des);
    g->adjmat[src] = add(g->adjmat[src], temp);

    temp = createnode(src);
    g->adjmat[des] = add(g->adjmat[des], temp);
}

void solve(graph *g, int start, int *visited)
{
    visited[start] = 1;
    printf("%d ", start);
    node *temp = g->adjmat[start];
    while (temp != NULL)
    {
        if (!visited[temp->value])
        {
            solve(g, temp->value, visited);
        }
        temp = temp->next;
    }
}

void dfs(graph *g, int start)
{
    int *visited = (int *)malloc(g->maxnode * sizeof(int));
    for (int i = 0; i < g->maxnode; i++)
    {
        visited[i] = 0;
    }
    solve(g, start, visited);
}

void bfs(graph *g, int start)
{
    int *visited = (int *)malloc(g->maxnode * sizeof(int));
    for (int i = 0; i < g->maxnode; i++)
    {
        visited[i] = 0;
    }
    int stk[max];
    int rear = 0;
    int front = 0;

    stk[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int element = stk[front++];
        printf("%d ", element);

        node *temp = g->adjmat[element];
        while (temp != NULL)
        {
            if (!visited[temp->value])
            {
                stk[rear++] = temp->value;
                visited[temp->value] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{

    graph *g = creategraph(10);

    addedge(g, 0, 1);
    addedge(g, 0, 2);
    addedge(g, 1, 3);
    addedge(g, 1, 4);
    addedge(g, 2, 5);
    addedge(g, 2, 6);

    bfs(g, 0);

    return 0;
}