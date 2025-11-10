//BFS traversal iteratively

#include<stdio.h>
#define max 10

int adj[max][max];
int visited[max];
int queue[max];
int front=-1,rear=-1;

void enqueue(int value){
    if(rear==max-1){printf("\nqueue overflow"); return;}
    if(front==-1) front=0;
    queue[++rear]=value;
}

int dequeue(){
    if(front>rear || front==-1)return -1;
    return queue[front++];
} 

void bfs(int start,int vert){
    front=rear=-1;
    for(int i=0;i<vert;i++){
        visited[i]=0;
    }
    enqueue(start);
    visited[start]=1;
    printf("\n bfs traversal starting from vertex %d: ",start);
    while(front<=rear){
        int curr=dequeue();
        printf("%d ",curr);
        for(int i=0;i<vert;i++){
            if(adj[curr][i]==1 && !visited[i]){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

int main(){
    int vert,edge,start;
    printf("enter number of vertices: ");
    scanf("%d",&vert);
    for(int i=0;i<vert;i++){
        for(int j=0;j<vert;j++){
            adj[i][j]=0;
        }
    }
    printf("enter number of edges: ");
    scanf("%d",&edge);
    for(int i=0;i<edge;i++){
        int u,v;
        printf("\nenter edge %d: ",i+1);
        scanf("%d%d",&u,&v);

        adj[u][v]=1;
        adj[v][u]=1;
    }
    printf("\nenter starting vertex: ");
    scanf("%d",&start);
    bfs(start,vert);
    return 0;
}