#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* creatNode(int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;

    return temp;
}

typedef struct Graph{
    int totalVertices;
    struct node *adjList[MAX];
}graph;


graph* createGraph(int totalVertices){
    graph* G = (graph*)malloc(sizeof(graph));
    G->totalVertices = MAX;

    for(int i=0;i<MAX;i++){
        G->adjList[i]=NULL;
    }

    return G;
}

struct node * add(struct node* head, struct node* temp){
    if(head==NULL) return temp;
    struct node* dummy = head;
    while (dummy->next!=NULL) 
    {
        dummy=dummy->next;
    }
    dummy->next=temp;
    return head;

}

void addEdge(graph* G, int src, int dest){
    struct node* temp = creatNode(dest);
    G->adjList[src]= add(G->adjList[src],temp);

    temp = creatNode(src);
    temp->next = G->adjList[dest];
    G->adjList[dest]=temp;
}

void solve(graph* G, int visited[], int start){
    visited[start]=1;
    printf("%d  ",start);

    struct node *temp = G->adjList[start];
     while(temp){
        int data = temp->data;
        if(!visited[data]){
            solve(G,visited,data);
        }
        temp=temp->next;
     }
}

void DFS(graph* G, int start){
    int *visited =(int*) malloc(G->totalVertices * sizeof(int));
    for (int i = 0; i < G->totalVertices; i++)
    {
        visited[i]=0;
    }
    solve(G,visited,start);
}



void BFS(graph* G, int start){
    int *visited = (int*)malloc(G->totalVertices*sizeof(int));
    for(int i=0;i<G->totalVertices;i++){
        visited[i]=0;
    }

    int queue[G->totalVertices];
    int rear=0, front=0;

    queue[rear++]=start;
    visited[start]=1;

    while (front<rear)
    {
       int curr = queue[front++] ;
       printf("%d   ", curr);

        struct node* temp = G->adjList[curr];
        while(temp){
            int data = temp->data;
            if(!visited[data]){
                visited[data]=1;
                queue[rear++]=data;
            }
            temp=temp->next;
        }

    }
    printf("\n");
    free(visited);
    
}



int main(){
    int totalVertices;
    graph* G = createGraph(totalVertices);
    addEdge(G,0,1);
    addEdge(G,0,2);
    addEdge(G,1,3);
    addEdge(G,1,4);
    addEdge(G,2,5);
    addEdge(G,2,6);

    DFS(G,0);
    // BFS(G,0);
}

