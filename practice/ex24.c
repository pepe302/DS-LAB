/* An adjacency matrix was given, you had to do dfs or bfs traversal and show the path like this
1->2->3->4*/

#include<stdio.h>
#include<stdlib.h>
#define max 8
int adj[max][max];
int visited[max];


//dfs by recursion
void dfs(int start,int vert){
    visited[start]=1;
    printf("%d -> ",start);
    for(int i=0;i<vert;i++){
        if(adj[start][i]==1 && visited[i]==0){
            dfs(i,vert);
        }
    }
}

//bfs by iteration
int queue[max];
int front=-1,rear=-1;

void enqueue(int vertex){
    if(rear==max-1) return;
    if(front==-1) front=0;
    queue[++rear]=vertex;
}

int dequeue(){
    if(front==-1) return 0;
    return queue[front++];
}

void bfs(int start, int vert){
    front=-1,rear=-1;
    for(int i=0;i<vert;i++){
        visited[i]=0;
    }
    enqueue(start);
    visited[start]=1;
    while(front<=rear){
        int curr=dequeue();
        printf("%d -> ",curr);
        for(int i=0;i<vert;i++){
            if(adj[curr][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    int vert,edge,start;
    printf("enter number of vertices: ");
    scanf("%d",&vert);
    printf("enter number of edges: ");
    scanf("%d",&edge);
    for(int i=0;i<vert;i++){
        visited[i]=0;
    }
    for(int i=0;i<vert;i++){
        for(int j=0;j<vert;j++){
            adj[i][j]=0;
        }
    }

    for(int i=0;i<edge;i++){
        int u,v;
        printf("enter edge %d: ",i+1);
        scanf("%d%d",&u,&v);

        if(u<0||v<0||u>=vert||v>=vert){
            printf("invalid edge");
            i--;
            continue;
        }

        adj[u][v]=1;
        adj[v][u]=1;
    }

    printf("enter starting vertex: ");
    scanf("%d",&start);
    printf("\ndfs traversal: ");
    dfs(start,vert);
    printf("\nbfs traversal: ");
    bfs(start,vert);

    return 0;
}