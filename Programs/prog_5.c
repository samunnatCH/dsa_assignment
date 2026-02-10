#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 20

typedef struct{
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

typedef struct{
    int items[MAX_VERTICES];
    int front,rear;
}Queue;

typedef struct{
    int items[MAX_VERTICES];
    int top;
}Stack;

void initGraph(Graph* g,int vertices){
    g->vertices=vertices;
    for(int i=0;i<vertices;i++)
        for(int j=0;j<vertices;j++)
            g->adjMatrix[i][j]=0;
}

void addEdge(Graph* g,int src,int dest){
    if(src>=0&&src<g->vertices&&dest>=0&&dest<g->vertices){
        g->adjMatrix[src][dest]=1;
        g->adjMatrix[dest][src]=1;
    }
}

void displayGraph(Graph* g){
    printf("\nAdjacency Matrix:\n   ");
    for(int i=0;i<g->vertices;i++)
        printf("%d ",i);
    printf("\n");
    for(int i=0;i<g->vertices;i++){
        printf("%d: ",i);
        for(int j=0;j<g->vertices;j++)
            printf("%d ",g->adjMatrix[i][j]);
        printf("\n");
    }
}

void initQueue(Queue* q){q->front=q->rear=-1;}
bool isQueueEmpty(Queue* q){return q->front==-1;}

void enqueue(Queue* q,int val){
    if(q->rear==MAX_VERTICES-1)return;
    if(q->front==-1)q->front=0;
    q->items[++q->rear]=val;
}

int dequeue(Queue* q){
    if(isQueueEmpty(q))return -1;
    int val=q->items[q->front++];
    if(q->front>q->rear)q->front=q->rear=-1;
    return val;
}

void initStack(Stack* s){s->top=-1;}
bool isStackEmpty(Stack* s){return s->top==-1;}

void push(Stack* s,int val){
    if(s->top==MAX_VERTICES-1)return;
    s->items[++s->top]=val;
}
int pop(Stack* s){
    if(isStackEmpty(s))return -1;
    return s->items[s->top--];
}
void BFS(Graph* g,int start){
    bool visited[MAX_VERTICES]={false};
    Queue q;
    initQueue(&q);
    printf("\nBFS: ");
    visited[start]=true;
    enqueue(&q,start);
    while(!isQueueEmpty(&q)){
        int v=dequeue(&q);
        printf("%d ",v);
        for(int i=0;i<g->vertices;i++){
            if(g->adjMatrix[v][i]&&!visited[i]){
                visited[i]=true;
                enqueue(&q,i);
            }
        }
    }
    printf("\n");
}
void DFS(Graph* g,int start){
    bool visited[MAX_VERTICES]={false};
    Stack s;
    initStack(&s);
    printf("DFS: ");
    push(&s,start);
    while(!isStackEmpty(&s)){
        int v=pop(&s);
        if(!visited[v]){
            printf("%d ",v);
            visited[v]=true;
        }
        for(int i=g->vertices-1;i>=0;i--){
            if(g->adjMatrix[v][i]&&!visited[i])
                push(&s,i);
        }
    }
    printf("\n");
}
int main(){
    Graph g;
    int vertices=7;
    printf("Graph using Adjacency Matrix\n\n");
    initGraph(&g,vertices);
    addEdge(&g,0,1);
    addEdge(&g,0,2);
    addEdge(&g,1,3);
    addEdge(&g,1,4);
    addEdge(&g,2,5);
    addEdge(&g,2,6);
    addEdge(&g,3,4);
    addEdge(&g,5,6);
    displayGraph(&g);
    BFS(&g,0);
    DFS(&g,0);
    BFS(&g,3);
    DFS(&g,3);
    return 0;
}
