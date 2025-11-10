//implement circular queue using arrays

#include<stdio.h>
#include<stdlib.h>

#define max 10

int queue[max];
int front=-1,rear=-1;

int isEmpty(){
    return (front==-1);
}

int isFull(){
    return (((rear+1)%max)==front);
}

void enqueue(int ele){
    if(isFull()){
        printf("queue is full");
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%max;
    }
    queue[rear]=ele;
    printf("%d inserted into queue",ele);
}

void dequeue(){
    if(isEmpty()){
        printf("queue is empty");
    }
    int delVal=queue[front];
    printf("%d deleted from queue",delVal);

    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%max;
    }
}

void display(){
    if(isEmpty){
        printf("queue empty");
    }
   printf("queue: ");
   for(int i=front;i!=rear;i=(i+1)%max){
        printf("%d ",queue[i]);
   }
   printf("%d ",queue[rear]);
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
