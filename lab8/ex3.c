//implement queue using sll

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

int isEmpty(){
    return(front==NULL);
}

void enqueue(int e){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory alloc failed");
        return;
    }
    newNode->data=e;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
    printf("%d enqueued",e);
}

void dequeue(){
    if(isEmpty()){
        printf("queue is empty");
    }
    struct Node *temp=front;
    int v=temp->data;
    front=front->next; 
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
    printf("%d dequeued",v);
}

void display(){ 
    if(isEmpty()){
        printf("queue empty");
    }
    struct Node *temp=front;
    printf("queue :");
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("\n null");
}


int main(){
    int choice;
    do{
        printf("\n 1. enqueue");
        printf("\n 2. dequeue");
        printf("\n 3. display");
        printf("\n 4. exit");
        printf("\n enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                int ele;
                printf("enter element: ");
                scanf("%d",&ele);
                enqueue(ele);
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
