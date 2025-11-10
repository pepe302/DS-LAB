//array based queue to simulate a printer queue

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 10

struct PrintJob{
    int docId;
    char docName[25];
};

int front=-1, rear =-1;
struct PrintJob queue[max];

int isEmpty(){
    return (front==-1 || front>rear);  //front>rear means queue was full and is now empty
}

int isFull(){
    return (rear==max-1);
} 

void enqueue(struct PrintJob job){
    if(!isFull()){
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=job;
        printf("enqueued");
    }
    else{
        printf("queue is full");
    }
}

void dequeue(){
    if(!isEmpty()){
        struct PrintJob job=queue[front];
        printf("\nprinting document... %d  %s",job.docId,job.docName);
        front++;
        if(front>rear){
            front=-1,rear=-1;
        }
    }
    else{
        printf("queue is empty");
    }
}

void displayQueue(){
    if(!isEmpty()){
        for(int i=front;i<=rear;i++){
            printf("Doc Id: %d   Doc Name: %s", queue[i].docId,queue[i].docName);
        }
    }
    else{
        printf("queue is empty");
    }
}

int main(){
    int choice;
    struct PrintJob job;
    do{
        printf("\nprinter menu");
        printf("\n1.add new print job");
        printf("\n2.print document");
        printf("\n3.view queue");
        printf("\n4.exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter doc id: ");
                scanf("%d",&job.docId);
                getchar();
                printf("enter doc name:");
                fgets(job.docName,25,stdin);
                job.docName[strcspn(job.docName,"\n")]='\0';
                enqueue(job);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                displayQueue();
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