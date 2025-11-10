//user defined functions on binary tree

#include<stdio.h>
#include<stdlib.h>
#define max 10

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node *createNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *queue[max];
int front=-1,rear=-1;

void enqueue(struct Node *data){
    if(rear==max-1)return;
    if(front==-1) front=0;
    queue[++rear]=data;
}

struct Node *dequeue(){
    if(front>rear || front==-1)return NULL;
    return queue[front++];
}

struct Node *createTree(){
    int data;
    printf("\nenter root: ");
    scanf("%d",&data);
    if(data==-1)return NULL;
    struct Node *root=createNode(data);
    enqueue(root);
    while(front<=rear){
        struct Node *curr=dequeue();
        int leftData,rightData;
        printf("enter left child of %d",curr->data);
        scanf("%d",&leftData);
        if(leftData!=-1){
            curr->left=leftData;
            enqueue(curr->left);
        }
        printf("enter right child of %d",curr->data);
        scanf("%d",&rightData);
        if(rightData!=-1){
            curr->right=rightData;
            enqueue(curr->right);
        }
    }
    return root;
}

void inorder(struct Node *root){
    struct Node *stack[max];
    int top=-1;
    struct Node *curr=root;
    while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            stack[++top]=curr;
            curr=curr->left;
        }
        curr=stack[top--];
        printf("%d ",curr->data);
        curr=curr->right;
    }
}

void preorder(struct Node *root){
    if(root==NULL)return;
    struct Node *stack[max];
    int top=-1;
    stack[++top]=root;
    while(top!=-1){
        struct Node *curr=stack[top--];
        printf("%d ",curr->data);

        if(curr->left) stack[++top]=curr->right;
        if(curr->right) stack[++top]=curr->left;
    }
}

void postorder(struct Node *root){
    if(root==NULL) return;
    struct Node *stack1[max], *stack2[max];
    int top1=-1,top2=-1;
    stack1[++top1]=root;
    while(top1!=-1){
        struct Node *curr=stack1[top1--];
        stack2[++top2]=curr;

        if(curr->left) stack1[++top1]=curr->left;
        if(curr->right) stack2[++top2]=curr->right;
    }
    while(top2!=-1){
        printf("%d ",stack2[top2--]->data);
    }
}

