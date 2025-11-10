//graphs using adjacency list

#include<stdio.h>
#include<stdlib.h>

#define max 10

struct Node{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int vertex){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=vertex;
    newNode->next=NULL;
    return newNode;
}

struct Node *graph[max];
int vert=0;

void addEdge(int u, int v, int choice){
    struct Node *newNode=createNode(v);
    newNode->next=graph[u];
    graph[u]=newNode;

    if(choice==2){
        struct Node* newNode=createNode(u);
        newNode->next=graph[v];
        graph[v]=newNode;
    }
}

void display(){
    for(int i=0;i<vert;i++){
        struct Node *temp=graph[i];
        printf("Vertex %d: ",i);
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf(" NULL\n");
    }
}

int main(){
    int edge,choice;
    printf("enter number of vertices: ");
    scanf("%d",&vert);
    for(int i=0;i<vert;i++){
        graph[i]=NULL;
    }
    printf("enter number of edges: ");
    scanf("%d",&edge);
    printf("\n1.Directed graph\n2.Undirected Graph\nenter choice: ");
    scanf("%d",&choice);
    for(int i=0;i<edge;i++){
        int u,v;
        printf("enter edge %d: ",i+1);
        scanf("%d%d",&u,&v);

        if(u<0 ||v<0 || u>=vert ||v>=vert){
            printf("\ninvalid choice. try again");
            i--;
            continue;
        }

        addEdge(u,v,choice);
    }
    display();
    return 0;
}
