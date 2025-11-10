//recursive function for binary tree

#include<stdio.h>
#include<stdlib.h>

#define max 10

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node *createNode(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *createTree(){
    int data;
    printf("enter data (-1 for no value): ");
    scanf("%d",&data);
    if(data==-1) return NULL;
    struct Node *newNode=createNode(data);
    printf("\nenter left child of %d: ",&data);
    newNode->left=createTree();
    printf("\nenter right child of %d: ",&data);
    newNode->right=createTree();
    return newNode;
}

void levelOrder(struct Node *root){
    if(root==NULL) return;
    struct Node *queue[max];
    int front=-1,rear=-1;
    queue[++rear]=root;
    printf("\nlevel order traversal: ");
    while(front!=rear){
        struct Node *curr=queue[++front];
        printf("%d",curr->data);
        if(curr->left!=NULL){
            queue[++rear]=curr->left;
        }
        if(curr->right!=NULL){
            queue[++rear]=curr->right;
        }
        printf("\n");
    }
}

int main(){
    printf("create binary tree: ");
    struct Node *root=createTree();
    levelOrder(root);
    return 0;
}