/*Tech Tatva participants simulation : 
—> insertion based on the order they are entered ( basically Linear Queue )
—> Create a queue of structures : structure for storing participant:
Name, event name , reg_id*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define n 10

struct Node{
    char name[25];
    char event[25];
    int reg_id;
    struct Node *next;
}*front=NULL,*rear=NULL;

struct Node *createNode(char name[25],char event[25],int reg_id){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name,name);
    strcpy(newNode->event,event);
    newNode->reg_id=reg_id;
    newNode->next=NULL;
    return newNode;
}

void enqueue(char name[],char event[],int reg_id){
    struct Node *newNode=createNode(name,event,reg_id);
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
        printf("empty queue");
        return;
    }
    struct Node *temp=front;
    while(temp!=NULL){
        printf("\nName: %s\nEvent: %s\nReg_id: %d",temp->name,temp->event,temp->reg_id);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice,reg_id;
    char name[25],event[25];
    do{
        printf("\n1.enter information ");
        printf("\n2.remove participant");
        printf("\n3.display details");
        printf("\n4.exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("enter participant name: ");
                fgets(name,25,stdin);
                name[strcspn(name,"\n")]='\0';
                printf("enter participant event: ");
                fgets(event,25,stdin);
                event[strcspn(event,"\n")]='\0';
                printf("enter reg_id: ");
                scanf("%d",&reg_id);
                enqueue(name,event,reg_id);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
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