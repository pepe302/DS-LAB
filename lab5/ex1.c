//doubly linked lists operations

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}*head;

void create_node(){
    struct Node *newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }

    printf("enter element into node: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void display(){
    struct Node *temp;
    if(head==NULL){
        printf("empty list");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf(" %d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void delete_rear(){
    struct Node *temp,*temp2;
    if(head==NULL){
        printf("empty list");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void insert_before(){
    struct Node *temp=head,*newNode;
    int ele;

    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }

    printf("enter element into node: ");
    scanf("%d",&newNode->data);
    printf("enter element to insert before: ");
    scanf("%d",&ele);

    if(head!=NULL && head->data==ele){
        newNode->next=head;
        newNode->prev=NULL;
        head->prev=newNode;
        head=newNode;
        return;
    }

    while(temp!=NULL && temp->data!=ele){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("element not found");
        free(newNode);
        return;
    }

    newNode->next=temp;
    newNode->prev=temp->prev;
    if(temp->prev!=NULL){
        temp->prev->next=newNode;
    }
    temp->prev=newNode;
}

void insert_after(){
    struct Node *temp=head,*newNode;
    int ele;

    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }

    printf("enter element into node: ");
    scanf("%d",&newNode->data);
    printf("enter element to insert after: ");
    scanf("%d",&ele);

    while(temp!=NULL && temp->data!=ele){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("element not found");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL){
            temp->next->prev=newNode;
    }
    temp->next=newNode;
}

void insert_pos(){
    struct Node *temp=head,*newNode;
    int pos,i=0;

    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }

    printf("enter element into node: ");
    scanf("%d",&newNode->data);
    printf("enter position to insert at: ");
    scanf("%d",&pos);

    if(pos==1){
        newNode->next=head;
        newNode->prev=NULL;
        if(head!=NULL){
            head->prev=newNode;
        }
        head=newNode;
        return;
    }

    while(temp!=NULL && i<pos-1){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
}

void delete_pos(){
    struct Node *temp;
    int pos,i=1;
    if(head==NULL){
        printf("empty list");
        return;
    }
    printf("enter position to delete from: ");
    scanf("%d",&pos);
    if(pos==1){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(temp);
        return;
    }

    while(temp!=NULL && i<pos){
        temp=temp->next;
        i++;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void traverse_backward(){
    struct Node *temp=head;
    if(head==NULL){
        printf("empty list");
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->prev;
    }
    printf("NULL");
}

int main(){
    int choice;
    do{
        printf("\nMenu: ");
        printf("\n1.create node/list");
        printf("\n2.delete an element");
        printf("\n3.traverse in forward direction");
        printf("\n4.insert element before another element");
        printf("\n5.insert element after another element");
        printf("\n6.reverse list");
        printf("\n7.sort in ascending order");
        printf("\n8.delete alternating node");
        printf("\n9.insert element into sorted list");
        printf("\n10.delete an element from the given position");
        printf("\n11.traverse in backward direction");
        printf("\n12.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                    create_node();
                    break;

            case 3: 
                    display();
                    break;
          
            case 10: 
                    printf("\nexiting..");
                    exit(0);
            default: 
                    printf("invalid choice");
                    break;
        }
    }while(choice!=10);
    return 0;
}
    