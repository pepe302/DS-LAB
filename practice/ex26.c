/*Creating binary tree using level order input, and then preorder, height, longest path from root to leaf nodes 
( had to show by printing vertices in path too), count no of leaf and non leaf node*/

#include<stdio.h>
#include<stdlib.h>

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

struct Node *insert(struct Node *root, int data){
    
}

void preorder(struct Node *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int height(struct Node *root){
    if(root==NULL) return -1;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return (leftH>rightH?leftH:rightH)+1;
}

void count(struct Node *root){
    int l=0,nl=0;
    if(root==NULL) return;
    while(root->left!=NULL && root->right!=NULL){
        
    }
}