/*Creating binary tree using level order input, and then preorder, height, longest path from root to leaf nodes 
( had to show by printing vertices in path too), count no of leaf and non leaf node*/

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

struct Node*queue[max];
int front=-1,rear=-1;

void enqueue(struct Node *node){
    if(rear==max-1) return;
    if(front==-1) front=0;
    queue[++rear]=node;
}

struct Node *dequeue(){
    if(front==-1 || front>rear) return NULL;
    return queue[front++];
}

struct Node *createTree(struct Node *root,int data){
    struct Node *newNode=createNode(data);
    if(root==NULL){
        root=newNode;
        return root;
    }
    front=0,rear=-1;
    enqueue(root);
    while(front<=rear){
        struct Node *curr=dequeue();
        if(curr->left==NULL){
            curr->left=newNode;
            printf("%d inserted as left child of %d",newNode->data,curr->data);
            return root;
        }
        else{
            enqueue(curr->left);
        }
        if(curr->right==NULL){
            curr->right=newNode;
            printf("%d inserted as right child of %d",newNode->data,curr->data);
            return root;
        }
        else{
            enqueue(curr->right);
        }
    }
    return root;
}

void preorder(struct Node *root){
    if(root==NULL) return;
    printf("%d -> ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int height(struct Node *root){
    if(root==NULL) return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return (leftH>rightH?leftH:rightH)+1;
}

void printPath(struct Node *root){
    if(root==NULL) return;
    printf("longest path from root to leaf: ");
    while(root!=NULL){
        printf("%d -> ",root->data);
        int leftH=height(root->left);
        int rightH=height(root->right);

        if(leftH>=rightH){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    printf("\n");
}

int countNodes(struct Node *root){
    if(root==NULL) return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

int countLeaf(struct Node *root){
    if(root==NULL) return 0;
    if(root->left==NULL  && root->right==NULL) return 1;
    return countLeaf(root->left)+countLeaf(root->right);
}

int main(){
    struct Node *root=NULL;
    int choice,h,data;
    do{
        printf("\n1.create tree");
        printf("\n2.preorder traversal");
        printf("\n3.height");
        printf("\n4.longest path from root to leaf");
        printf("\n5.count leaf and non leaf");
        printf("\n6.exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("enter data: ");
                scanf("%d",&data);
                root=createTree(root,data);
                break;

            case 2:
                preorder(root);
                break;
            
            case 3:
                h=height(root);
                printf("height: %d",h);
                break;

            case 4: 
                printPath(root);
                break;

            case 5:
                printf("\nNon leaf nodes: %d",countNodes(root));
                printf("\nLeaf Nodes: %d",countLeaf(root));
                break;
            
            case 6:
                printf("exiting..");
                exit(0);

            default:
                printf("invalid choice");
        }
    }while(choice!=6);
    return 0;
}