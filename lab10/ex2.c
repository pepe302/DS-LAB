//avl tree and perform insertion 
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *right,*left;
    int height;
};

int height(struct Node *node){
    if(node==NULL)return 0;
    return node->height;
}

int maximum(int a,int b){
    return (a>b?a:b);
}

int getBalance(struct Node *node){
    if(node==NULL) return 0;
    return height(node->left)-height(node->right);
}

struct Node *createNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}

struct Node *RR(struct Node *y){
       struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *LR(struct Node *x){
struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // new root
}

struct Node *insert(struct Node *node, int data){
    if(node==NULL) return createNode(data);
    if(data>node->data){
        node->right=insert(node->right,data);
    }
    if(data<node->data){
        node->left=insert(node->left,data);
    }
    else{return node;}

    node->height=1+maximum(height(node->left),height(node->right));
    int bal=getBalance(node);

    if(bal>1 && data<node->left->data){
        return RR(node);
    }
    if(bal<-1 && data>node->right->data){
        return LL(node);
    }
    if(bal>1 && data>node->left->data){
        node->left=LL(node->left);
        return RR(node);
    }
    if(bal<-1 && data<node->right->data){
        node->right=RR(node->right);
        return LL(node);
    }
    return node;
}

void inorder(struct Node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
     struct Node *root = NULL;
    int choice, data;

    while (1) {
        printf("\n--- AVL Tree Operations ---");
        printf("\n1. Insert");
        printf("\n2. Display (Inorder)");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Inserted %d successfuLRy.\n", data);
            break;

        case 2:
            printf("Inorder Traversal (sorted): ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}