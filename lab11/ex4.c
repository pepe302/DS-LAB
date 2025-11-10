//dfs traversal recursively

#include<stdio.h>

#define max 10

int adj[max][max];
int visited[max];

void dfs(int start, int vert){
    visited[start]=1;
    printf("%d ",start);

    for(int i=0;i<vert;i++){
        if(adj[start][i]==1 && visited[i]==0){
            dfs(i,vert);
        }
    }
}

int main(){
    int vert,edges,start;
    printf("enter number of vertices: ");
    scanf("%d",&vert);
    printf("enter number of edges: ");
    scanf("%d",&edges);
    for(int i=0;i<vert;i++){
        visited[i]=0;
    }
    for(int i=0;i<edges;i++){
        int u,v;
        printf("enter edge %d: ",i+1);
        scanf("%d%d",&u,&v);

        if(u<0 || v<0 || u>=vert || v>=vert){
            printf("invalid edge. try again");
            i--;
            continue;
        }
        adj[u][v]=1;
        adj[v][u]=1;
    }

    printf("\nenter starting vertex: ");
    scanf("%d",&start);
    printf("\ndfs traversal starting from %d: ", start);
    dfs(start,vert);
    return 0;
}