//circular linked lists operations

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next,*prev;
}*head;

void create_node(){
    struct Node *newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    
    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }

    printf("enter element: ");
    scanf("%d",&newNode->data);
    
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        newNode->prev=head;
        return;    
    }

    head->prev->next=newNode;
    newNode->next=head;
    newNode->prev=head->prev;
    head->prev=newNode;
}

void display(){
    struct Node *temp;
    if(head==NULL){
        printf("empty list");
        return;
    }
    temp=head;
    
    while(temp->next!=head){
        printf(" %d -> ",temp->data);
        temp=temp->next;
        if(temp->next==head){
            printf(" %d -> ",temp->data);
            printf("head");
        }
    }

}

void delete_start(){

    if(head==NULL){
        printf("empty list");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    head->prev->next=head->next;
    head->next->prev=head->prev;
    free(head);
    head=head->next;
}

void delete_end(){

    if(head==NULL){
        printf("empty list");
        return;
    }
    if(head->next==head){
         free(head);
        head=NULL;
        return;
    
    }
    struct Node *temp=head->prev;
    temp->prev->next=head;
    head->prev=temp->prev;
    free(temp);


}
int main(){
    int choice;
    do{
        printf("\nMenu: ");
        printf("\n1.create node/list");
        printf("\n2.delete an element from start");
        printf("\n3.delete an element from end");
        printf("\n4.display");
        printf("\n5.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                create_node();
                break;

            case 2: 
                delete_start();
                display();
                break;
        
            case 3:
                delete_end();
                display();
                break;
            
            case 4: 
                display();
                break;

            case 5: 
                printf("\nexiting..");
                exit(0);

            default: 
                    printf("invalid choice");
                    break;
        }
    }while(choice!=5);
    return 0;
}