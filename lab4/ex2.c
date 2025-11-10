//create and traverse linked list recursively

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

struct Node *create_node(){
    int choice;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("enter data: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    printf("1 to continue | 2 to exit ");
    scanf("%d",&choice);
    if(choice==1){
        newNode->next=create_node();
    }
    return newNode;
};

void display(struct Node *p){
    if(p==NULL){
        return;
    }
    printf("%d->",p->data);
    display(p->next);
}


int main(){
int choice;
    do{
        printf("\nMenu: ");
        printf("\n1.create node/list");
        printf("\n2.traverse and display");
        printf("\n3.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                    if(head==NULL){
                        head=create_node();
                    }
                    else{
                        printf("list created already\n");
                    }
                    break;
            case 2:
                    display(head);
                    printf("NULL");
                    break;
            case 3: 
                    printf("\nexiting..");
                    exit(0);
            default: 
                    printf("invalid choice");
                    break;
        }
    }while(choice!=3);
    return 0;
}