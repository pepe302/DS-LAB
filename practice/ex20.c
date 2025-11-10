/*A company stores employee IDs in a tree (use a BST) so that each ID can be quickly searched. 
Write a program to add employee IDs, search for a particular ID, remove an ID, and display all IDs in sorted order.*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int id;
    struct Node *left,*right;
};

struct Node *createNode(int id){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->id=id;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int id){
    if(root==NULL) return createNode(id);
    if(id>root->id){
        root->right=insert(root->right,id);
    }
    if(id<root->id){
        root->left=insert(root->left,id);
    }
    return root;
}

struct Node *search(struct Node *root, int id){
    if(root==NULL ||root->id==id) return root;
    if(id<root->id){
        return search(root->left,id);
    }
    if(id>root->id){
        return search(root->right,id);
    }
}

struct Node *findMin(struct Node *root){
    if(root==NULL) return NULL;
    struct Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct Node *deleteNode(struct Node *root, int id){
    if(root==NULL) return NULL;
    if(id<root->id){
        root->left=deleteNode(root->left,id);
    }
    else if(id>root->id){
        root->right=deleteNode(root->right,id);
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
        root->id=temp->id;
        root->right=deleteNode(root->right,temp->id);
    }
    return root;
}

void inorder(struct Node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->id);
    inorder(root->right);
}
int main(){
    struct Node *root=NULL,*n;
    int choice,id;
    do{
        printf("\n1.Add ID");
        printf("\n2.Search ID");
        printf("\n3.Remove ID");
        printf("\n4.Display all IDs in sorted order");
        printf("\n5.exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("enter ID: ");
                scanf("%d",&id);
                root=insert(root,id);
                break;

            case 2: 
                printf("enter ID: ");
                scanf("%d",&id);
                n=search(root,id);
                if(n!=NULL){
                    printf("%d found",id);
                }
                else{
                    printf("not found");
                }
                break;

            case 3: 
                printf("enter ID: ");
                scanf("%d",&id);
                root=deleteNode(root,id);
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                printf("exiting..");
                exit(0);
                
            default:
                printf("invalid choice");
        }
    }while(choice!=5);
    return 0;
}