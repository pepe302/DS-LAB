/*Implement a BST for Simulating for Women’s World Cup participants registration:

Members left, right, rank_id, team name 

Operations: 
—> Insert using recursion
—> Post order traversal ( iterative version ) 
—> Deletenode from BST 
—> display the outputs of FindMin & FindMax after deleting the root node*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[25];
    int rank_id;
    struct Node *left,*right;
};

struct Node *createNode(char name[],int rank_id){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory allocation failed");
        return NULL;
    }
    strcpy(newNode->name,name);
    newNode->rank_id=rank_id;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insert(struct Node *root,char name[],int rank_id){
    if(root==NULL) return createNode(name,rank_id);
    if(rank_id>root->rank_id){
        root->right=insert(root->right,name,rank_id);
    }
    if(rank_id<root->rank_id){
        root->left=insert(root->left,name,rank_id);
    }
    return root;
}

void postorder(struct Node *root){
    if(root==NULL) return;
    struct Node *stack1[10],*stack2[10];
    int top1=-1,top2=-1;
    stack1[++top1]=root;
    while(top1!=-1){
        struct Node *curr=stack1[top1--];
        stack2[++top2]=curr;

        if(curr->left) stack1[++top1]=curr->left;
        if(curr->right) stack1[++top1]=curr->right;
    }
    while(top2!=-1){
        struct Node *curr=stack2[top2--];
        printf("\nName: %s\nRank_id: %d",curr->name, curr->rank_id);
    }
}


struct Node *findMin(struct Node *root){
    if(root==NULL) return NULL;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node *findMax(struct Node *root){
    if(root==NULL) return NULL;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct Node *deleteNode(struct Node *root,int rank_id){
    if(root==NULL) return root;
    if(rank_id>root->rank_id){
        root->right=deleteNode(root->right,rank_id);
    }
    else if(rank_id<root->rank_id){
        root->left=deleteNode(root->left,rank_id);
    }
    else{
        if(root->left==NULL){
            struct Node *temp=root->right;
            free(root);
            return temp;
        }

        if(root->right==NULL){
            struct Node *temp=root->left;
            free(root);
            return temp;
        }

        struct Node *temp=findMin(root->right);
        strcpy(root->name,temp->name);
        root->rank_id=temp->rank_id;
        root->right=deleteNode(root->right,temp->rank_id);
    }
    return root;
}

int main(){
    struct Node *root=NULL;
    int choice;
    char name[25];
    int rank_id;
    do{
        printf("\nMenu details: ");
        printf("\n1.insert node");
        printf("\n2.delete node");
        printf("\n3.postorder traversal");
        printf("\n4.find minimum rank");
        printf("\n5.find maximum rank");
        printf("\n6.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:     
                printf("enter team name: ");
                fgets(name,25,stdin);
                name[strcspn(name,"\n")]='\0';
                printf("enter rank_id: ");
                scanf("%d",&rank_id);
                root=insert(root,name,rank_id);
                break;
            case 2: 
                int n;
                printf("enter rank id to delete: ");
                scanf("%d",&n);
                root=deleteNode(root,n);
                break;

            case 3: 
                postorder(root);
                break;

            case 4:{
                struct Node *minNode=findMin(root);
                if(minNode){
                    printf("\nMinimum rank: %d |  Team: %s",minNode->rank_id,minNode->name);
                }
                else{
                    printf("tree is empty");
                }
                break;
            }
            case 5:{
                struct Node *maxNode=findMax(root);
                if(maxNode){
                    printf("\nMaximum rank: %d | Team: %s",maxNode->rank_id,maxNode->name);
                }
                else{
                    printf("tree is empty");
                }
                break;
            }
            case 6: 
                printf("exiting...");
                break;

            default:
                printf("invalid choice");
                break;
        }
    }while(choice!=6);
    return 0;
}