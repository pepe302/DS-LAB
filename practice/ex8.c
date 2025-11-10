/*bus route management using singly linked lists
ROUTE A AND ROUTE B
1) for route A function for inserting a bus stop before a specified stop
2) Add and display BUS STOPS for respective Routes*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int stop;
    struct Node *next;
};

void create_node(struct Node **head){
    struct Node *newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter stop: ");
    scanf("%d",&newNode->stop);
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
};
void add_before(struct Node **head){
    struct Node *newNode,*temp;
    int ele;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter stop: ");
    scanf("%d",&newNode->stop);
    newNode->next=NULL;
    printf("enter stop to insert before:");
    scanf("%d",&ele);
    if((*head)->stop==ele){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    else{
        temp=*head;
        while(temp!=NULL && temp->next->stop!=ele){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
};

void display(struct Node *head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->stop);
        temp=temp->next;
    }
    printf("END");
}

int main(){
    struct Node *head1=NULL,*head2=NULL;
    int choice;
    do{
        printf("\nMenu details: ");
        printf("\n1.create route A");
        printf("\n2.create route B");
        printf("\n3.add new stop before another stop for route A: ");
        printf("\n4.add new stop before another stop for route B: ");
        printf("\n5.display route A");
        printf("\n6.display route B");
        printf("\n7.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:     
                create_node(&head1);
                break;
            case 2: 
                create_node(&head2);
                break;
            case 3:
                add_before(&head1);
                break;
            case 4:
                add_before(&head2);
                break;
            case 5: 
                printf("route a: ");
                display(head1);
                break;
            case 6: 
                printf("route b: ");
                display(head2);
                break;
            case 7:
                printf("exiting...");
                break;
            default:
                printf("invalid choice");
                break;
        }
    }while(choice!=7);
    return 0;
}