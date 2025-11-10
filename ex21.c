/*Implement menu driven DLL for tabs , the data should be name of the tab ,
implement opening of a new tab and deletion of the last tab .
and display all the tabs from left to right .*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[25];
    struct Node *next,*prev;
};

struct Node *createNode(char name[]){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory allocation failed");
        return NULL;
    }
    strcpy(newNode->name,name);
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

struct Node *insert(struct Node *head,char name[]){
    struct Node *newNode=createNode(name);
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

struct Node* deleteNode(struct Node *head){
    if(head==NULL){
        printf("list is empty");
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }

    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}

void display(struct Node *head){
    if(head==NULL){
        printf("empty list");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("[%s] ->",temp->name);
        temp=temp->next;
    }
    printf("NULL \n");
}

int main(){
    struct Node *head=NULL;
    char name[25];
    int choice;
    do{
    printf("\n1.Open new tab");
    printf("\n2.Delete last tab");
    printf("\n3.Display tabs from left to right");
    printf("\n4.exit");
    printf("\nenter choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("enter tab name: ");
            fgets(name,25,stdin);
            name[strcspn(name,"\n")]='\0';
            head=insert(head,name);
            break;

        case 2: 
            head=deleteNode(head);
            break;

        case 3:
            display(head);
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