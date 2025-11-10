//adjacency matrix for directed and undirected graphs

#include<stdio.h>
#define max 10

void display(int mat[][max], int vert){
    for(int i=0;i<vert;i++){
        for(int j=0;j<vert;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int mat[max][max]={0};
    int vert,edges,choice;
    printf("enter number of vertices: ");
    scanf("%d",&vert);
    printf("enter number of edges: ");
    scanf("%d",&edges);
    printf("\n1.Directed Graph\n2.Undirected Graph\nEnter choice:");
    scanf("%d",&choice);
    for(int i=0;i<edges;i++){
        int u,v;
        printf("enter edge %d: ",i+1);
        scanf("%d%d",&u,&v);

        if(u<0 || v<0 || u>=vert ||v>=vert){
            printf("\ninvalid entry");
            break;
        }

        if(choice==1){
            mat[u][v]=1;
        }
        else if(choice==2){
            mat[u][v]=1;
            mat[v][u]=1;
        }
        else{
            printf("\ninvalid choice. try again");
        }
    }
    display(mat,vert);
    return 0;
}