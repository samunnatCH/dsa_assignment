#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 20
#define INF INT_MAX

typedef struct {
    int vertices;
    int adj[MAX][MAX];
} Graph;

void initGraph(Graph *g,int n){
    g->vertices=n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) g->adj[i][j]=0;
}

void addEdge(Graph *g,int u,int v,int w){
    g->adj[u][v]=w;
    g->adj[v][u]=w;
}

int minDistance(int dist[],bool visited[],int n){
    int min=INF,minIndex=-1;
    for(int i=0;i<n;i++)
        if(!visited[i] && dist[i]<min){min=dist[i]; minIndex=i;}
    return minIndex;
}

void dijkstra(Graph *g,int src){
    int dist[MAX];
    bool visited[MAX]={false};
    for(int i=0;i<g->vertices;i++) dist[i]=INF;
    dist[src]=0;

    for(int count=0;count<g->vertices-1;count++){
        int u=minDistance(dist,visited,g->vertices);
        if(u==-1) break;
        visited[u]=true;
        for(int v=0;v<g->vertices;v++)
            if(!visited[v] && g->adj[u][v] && dist[u]+g->adj[u][v]<dist[v])
                dist[v]=dist[u]+g->adj[u][v];
    }

    printf("Shortest distances from vertex %d:\n",src);
    for(int i=0;i<g->vertices;i++){
        if(dist[i]==INF) printf("%d -> INF\n",i);
        else printf("%d -> %d\n",i,dist[i]);
    }
}

int main(){
    Graph g;
    int n=6;
    initGraph(&g,n);

    addEdge(&g,0,1,4);
    addEdge(&g,0,2,3);
    addEdge(&g,1,2,1);
    addEdge(&g,1,3,2);
    addEdge(&g,2,3,4);
    addEdge(&g,3,4,2);
    addEdge(&g,4,5,6);
    addEdge(&g,2,4,5);

    dijkstra(&g,0);
    printf("\n");
    dijkstra(&g,3);

    return 0;
}
