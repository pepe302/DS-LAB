/*Use doubly linked linkedlist to add a record containing
Plot ID, Farmer Name, Name of Crop, Time and Water required, 
then display all records, reschedule time using plot id,
 display the total water required for a specific crop
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int id,time,water;
    char crop[25],name[25];
    struct Node *next,*prev;
};

struct Node *createNode(int id,int time,int water,char crop[],char name[]){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->id=id;
    newNode->time=time;
    newNode->water=water;
    strcpy(newNode->crop,crop);
    strcpy(newNode->name,name);
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

struct Node *insert(struct Node *head,int id,int time,int water,char crop[],char name[]){
    struct Node *newNode=createNode(id,time,water,crop,name);
    if(head==NULL){
        head=newNode;
        return head;
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

struct Node *reschedule(struct Node *head,int id,int time){
    if(head==NULL){
        printf("empty");
        return NULL;
    }
    struct Node *temp=head;
    while(temp->id!=id){
        temp=temp->next;
    }
    temp->time=time;
    return head;
}

void total(struct Node *head, char crop[]){
    int sum=0;
    if(head==NULL){
        printf("empty land");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        if(strcmp(temp->crop,crop)==0){
            sum+=temp->water;
        }
        temp=temp->next;
    }
    printf("Total water required for %s : %d",crop,sum);
}

void display(struct Node *head){
    if(head==NULL){
        printf("empty list");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("\nPlot ID: %d",temp->id);
        printf("\nCrop name: %s",temp->crop);
        printf("\nFarmer name: %s",temp->name);
        printf("\nTime for growth: %d",temp->time);
        printf("\nWater Required(in litres): %d",temp->water);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct Node *head=NULL;
    int choice,id,time,water,retime;
    char crop[25],name[25];
    do{
        printf("\n1.Add record");
        printf("\n2.Reschedule time");
        printf("\n3.Total water for a crop");
        printf("\n4.Display all records");
        printf("\n5.exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("enter farmer name: ");
                fgets(name,25,stdin);
                name[strcspn(name,"\n")]='\0';
                printf("enter crop name: ");
                fgets(crop,25,stdin);
                crop[strcspn(crop,"\n")]='\0';
                printf("enter plot_id: ");
                scanf("%d",&id);
                printf("enter hours: ");
                scanf("%d",&time);
                printf("enter water required: ");
                scanf("%d",&water);
                head=insert(head,id,time,water,crop,name);
                break;

            case 2: 
                printf("\nenter plot ID: ");
                scanf("%d",&id);
                printf("\nrescheduled time: ");
                scanf("%d",&retime);
                head=reschedule(head,id,retime);
                break;

            case 3: 
                printf("enter crop: ");
                fgets(crop,25,stdin);
                crop[strcspn(crop,"\n")]='\0';
                total(head,crop);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("exiting..");
                exit(0);
                
            default:
                printf("invalid choice");
        }
    }while(choice!=5);
    return 0;
}
