/*A bank issues tokens to customers as they arrive. Each customer waits in a line and is served in the order of arrival.
Write a program to manage 
issuing tokens,serving customers, and displaying the list of waiting customers.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
char Name[25];
int token;
struct Node *next;
}*front=NULL,*rear=NULL;

struct Node *createNode(char name[], int token){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory alloc failed");
        return NULL;
    }
    strcpy(newNode->Name,name);
    newNode->token=token;
    newNode->next=NULL;
    return newNode;
}

void enqueue(char name[],int token){
    struct Node *newNode=createNode(name,token);
    if(front==NULL){
        front=rear=newNode;
    }
    rear->next=newNode;
    rear=newNode;
}

void dequeue(){
    if(front==NULL){
        printf("queue is empty");
        return;
    }
    struct Node *temp=front;
    front=front->next;
    free(temp);
}

void display(){
    if(front==NULL){
        printf("queue is empty");
        return;
    }
    struct Node *temp=front;
    while(temp!=NULL){
        printf("\nName: %s |Token: %d",temp->Name,temp->token);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
char name[25];
int choice,token;
do{
    printf("\n1.Issue Token");
    printf("\n2.Serve Customer");
    printf("\n3.Display Waiting customers");
    printf("\n4.exit");
    printf("\nenter choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("enter customer name: ");
            fgets(name,25,stdin);
            printf("enter token: ");
            scanf("%d",&token);
            enqueue(name,token);
            break;

        case 2: 
            dequeue();
            break;

        case 3: 
            display();
            break;

        case 4:
            printf("exiting..");
            exit(0);
            
        default:
            printf("invalid choice");
    }
}while(choice!=4);
return 0;
}
