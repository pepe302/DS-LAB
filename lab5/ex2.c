//concatenate two DLL

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next,*prev;
}*head;

void create_list(struct Node **list){
    int op;
    do{
        struct Node *newNode,*temp;
        newNode=(struct Node*)malloc(sizeof(struct Node));
        
        if(newNode==NULL){
            printf("memory not allocated");
            return;
        }

        printf("enter element: ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        newNode->prev=NULL;
        if(*list==NULL){
            *list=newNode;
        }else{
            temp=*list;
            while(temp->next!=NULL){
            temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
    
        printf("1 to continue | 2 to exit: ");
        scanf("%d",&op);
    }while(op!=2);
}

void display(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}


struct Node* concatenate(struct Node *X1, struct Node *X2){
    if(X1==NULL) return X2;
    if(X2==NULL) return X1;

    struct Node *temp=X1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=X2;
    X2->prev=temp;

    return X1;

}
int main(){
    struct Node *X1=NULL,*X2=NULL,*X3=NULL;
    printf("enter DLL 1: ");
    create_list(&X1);
    printf("\nenter DLL 2: ");
    create_list(&X2);
    printf("\nX1: ");
    display(X1);
    printf("\nX2: ");
    display(X2);
    printf("\n concatenated list: ");
    X3=concatenate(X1,X2);
    display(X3);
    return 0;
}