/*Stack using ll, push pop display*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

struct Node *push(struct Node *top,int data){
    struct Node *newNode=createNode(data);
    if(top==NULL){
        top=newNode;
        return top;
    }
    newNode->next=top;
    top=newNode;
    return top;
}

struct Node *pop(struct Node *top){
    if(top==NULL){
        printf("empty stack");
        return NULL;
    }
    printf("\n%d popped",top->data);
    struct Node *temp=top;
    top=top->next;
    free(temp);
    return top;
}

void display(struct Node *top){
    if(top==NULL){
        printf("empty stack");
        return;
    }
    while(top!=NULL){
        printf("\n%d",top->data);
        top=top->next;
    }
    printf("\n");
}

int main(){
    struct Node *top=NULL;
    int choice,data;
    do{
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display stack");
    printf("\n4.exit");
    printf("\nenter choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("enter data: ");
            scanf("%d",&data);
            top=push(top,data);
            break;

        case 2: 
            top=pop(top);
            break;

        case 3:
            display(top);
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