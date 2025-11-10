//linked list based queue of structures

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Patient{
    char name[25];
    int age;
    int priority; //1-highest 3-lowest
    struct Patient *next;
}*front=NULL;

int isEmpty(){
    return(front==NULL);
}

struct Patient *createPatient(char name[],int age, int priority){
    struct Patient *newPat=(struct Patient*)malloc(sizeof(struct Patient));
    strcpy(newPat->name,name);
    newPat->age=age;
    newPat->priority=priority;
    newPat->next=NULL;
    return newPat;
}

void enqueue(char name[], int age,int priority){
    struct Patient *newPatient=createPatient(name,age,priority);
    if(front==NULL || priority<front->priority){
        front=newPatient;
    } 
    else{
        struct Patient *temp=front;
        while(temp->next!=NULL && temp->next->priority<=priority){
            temp=temp->next;
        }
        newPatient->next=temp->next;
        temp->next=newPatient;
    }
    printf("patient added to queue");
}

void dequeue(){
    if(isEmpty()){
        printf("queue is empty");
    }
    struct Patient *temp=front;
    printf("Patient %s removed from queue",temp->name);
    front=front->next;
    free(temp);
}

void display(){
    if(isEmpty()){
        printf("queue is empty");
    }
    struct Patient *temp=front;
    while(temp!=NULL){
        printf("\n Name: %s      Age: %d    Priority: %d",temp->name,temp->age,temp->priority);
        temp=temp->next;
    }
    printf("\n null");
}

int main(){
int choice,age,priority;
char name[25];
do{
    printf("\n 1. enter details");
    printf("\n 2. remove details");
    printf("\n 3. display");
    printf("\n 4. exit");
    printf("\n enter choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1: 
            int ele;
            printf("\nenter name: ");
            fgets(name,25,stdin);
            name[strcspn(name,"\n")]='\0';
            printf("\nenter age: ");
            scanf("%d",&age);
            printf("\nenter priority (1: crit | 2: mod | 3:normal): ");
            scanf("%d",&priority);
            enqueue(name,age,priority);
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