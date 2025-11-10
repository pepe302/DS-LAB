//create BST and perform operations and traversals

#include<stdio.h>
#include<stdlib.h>

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

struct Node *insert(struct Node *root, int data){
    if(root==NULL) return createNode(data);
    if(data>root->data){
        root->right=insert(root->right,data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    return root;
}

void inorder(struct Node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct Node *search(struct Node *root, int key){
    if(root==NULL || root->data==key) return root;
    if(key>root->data) search(root->right,key);
    if(key<root->data) search(root->left,key);
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

struct Node *deleteNode(struct Node *root, int data){
    if(root==NULL) return root;
    if(data>root->data){
        root->right=deleteNode(root->right,data);
    }
    if(data<root->data){
        root->left=deleteNode(root->left,data);
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
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int main(){
        struct Node* root = NULL;
    int n, data;
    
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("Enter node %d: ", i+1);
        scanf("%d", &data);
        root = insertBST(root, data);
    }
    
    printf("Inorder traversal: "); inorder(root); printf("\n");
    printf("Preorder traversal: "); preorder(root); printf("\n");
    printf("Postorder traversal: "); postorder(root); printf("\n");
    
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
    struct Node* found = searchBST(root, key);
    if(found) printf("%d found in BST\n", key);
    else printf("%d not found in BST\n", key);
    
    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);
    if(minNode) printf("Minimum: %d\n", minNode->data);
    if(maxNode) printf("Maximum: %d\n", maxNode->data);
    
    printf("Enter element to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("Inorder after deletion: "); inorder(root); printf("\n");
    
    return 0;
}