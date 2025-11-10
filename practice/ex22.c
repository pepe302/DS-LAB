/*Implement Adjacency list for a graph , DFS , Maximum , minimum no. of edges
 for a given no. of vertex in connected directed/undirected graph*/

#include<stdio.h>
#include<stdlib.h>

#define max 10
struct Node{
   int vertex;
   struct Node *next;
};

struct Node *graph[max];
int visited[max];

struct Node *createNode(int vertex){
   struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->vertex=vertex;
   newNode->next=NULL;
   return newNode;
}

void addEdge(int u,int v,int choice){
   struct Node *newNode=createNode(v);
   newNode->next=graph[u];
   graph[u]=newNode;
   if(choice==2){
      struct Node *newNode=createNode(u);
      newNode->next=graph[v];
      graph[v]=newNode;
   }
}

void display(int vert){
   int minEdge=999;
   int maxEdge=0;
   for(int i=0;i<vert;i++){
      int count=0;
      struct Node *temp=graph[i];

      printf("\nvertex %d: ",i);
      while(temp!=NULL){
         printf("%d -> ",temp->vertex);
         count++;
         temp=temp->next;
      }
      if(count>maxEdge) maxEdge=count;
      if(count<minEdge) minEdge=count;
   }
   printf("\nminimum edges: %d",minEdge);
   printf("\nmaximum edges: %d",maxEdge);
}

void dfs(int start, int vert){
   visited[start]=1;
   printf("%d -> ",start);
   struct Node *temp=graph[start];
   while(temp!=NULL){
      if(!visited[temp->vertex]){
         dfs(temp->vertex,vert);
      }
      temp=temp->next;
   }
}  

int main(){
   int vert,edge,choice,start;
   printf("enter number of vertices:");
   scanf("%d",&vert);
   printf("enter edges: ");
   scanf("%d",&edge);
   printf("\n1.Directed graph\n2.Undirected graph\nenter choice: ");
   scanf("%d",&choice);
   for(int i=0;i<edge;i++){
      int u,v;
      printf("enter edge %d: ",i);
      scanf("%d%d",&u,&v);

      if(u<0||v<0||u>=vert||v>=vert){
         printf("invalid edge\n");
         i--;
         continue;
      }
      addEdge(u,v,choice);
   }
   for(int i=0;i<vert;i++){
      visited[i]=0;
   }
   printf("\nenter starting vertex: ");
   scanf("%d",&start);
   printf("\ndfs traversal: ");
   dfs(start,vert);
   printf("\nEdge statistics: ");
   display(vert);
   return 0;
}