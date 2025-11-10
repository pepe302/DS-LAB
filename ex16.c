/*Make a Binary tree whose nodes have words in it user input postorder traversal and height of tree*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[25];
    struct Node *left, *right;
};

struct Node *createNode(char data[]){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data,data);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insert(struct Node *root,char data[]){
    if(root==NULL) return createNode(data);
    if(strcmp(data,root->data)<0){
        root->left=insert(root->left,data);
    }
    if(strcmp(data,root->data)>0){
        root->right=insert(root->right,data);
    }
    return root;

}

int height(struct Node *node){
    if(node==NULL) return 0;
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);
    return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
}

void postorder(struct Node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%s ",root->data);
}

int main(){
    struct Node *root=NULL;
    int choice;
    char str[25];
    do{
        printf("\n1.input word");
        printf("\n2.postorder traversal");
        printf("\n3.height of tree");
        printf("\n4.exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("\nenter word: ");
                fgets(str,25,stdin);
                str[strcspn(str,"\n")]='\0';
                root=insert(root,str);
                break;

            case 2:
                postorder(root);
                break;

            case 3:
                printf("height of root: %d",height(root));
                break;

            case 4:
                printf("\nexiting..");
                break;
            
            default:
                printf("\ninvalid choice");
        }
    }while(choice!=4);
    return 0;
}