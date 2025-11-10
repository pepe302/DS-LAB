/*doubly linked list participants -
 each participant has email, name and reg. no 
 insert new in the middle delete first participant registration no.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    char email[30];
    char name[20];
    int reg_no;
    struct Node *prev,*next;
}*head=NULL;

void create_node(){
    struct Node*newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("\nenter email: ");
    scanf("%s",newNode->email);
    printf("\nenter name: ");
    scanf(" %s",newNode->name);
    printf("\nenter reg_no: ");
    scanf(" %d",&newNode->reg_no);

    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}


void delete_front(){
    if(head==NULL){
        printf("empty list");
        return;
    }
    else{
        int temp =head->reg_no;
        head->reg_no=head->next->reg_no;
        head->next->prev->reg_no=NULL;
       
    }
}
void insert_mid(){
    struct Node* newNode,*temp;
    int no;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("\nenter email: ");
    scanf("%s",newNode->email);
    printf("\nenter name: ");
    scanf(" %s",newNode->name);
    printf("\nenter reg_no: ");
    scanf(" %d",&newNode->reg_no);

    newNode->next=NULL;
    newNode->prev=NULL;
    printf("\nenter reg_no after which you want to insert: ");
    scanf("%d",&no);
    temp=head;
    while(temp!=NULL && temp->reg_no!=no){
       temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
    
}
void display(){
    struct Node*temp=head;
    printf("Student details:\n");
    while(temp!=NULL){
        printf("\nstudent email: %s",temp->email);
        printf("\nstudent name: %s",temp->name);
        printf("\nstudent regno: %d",temp->reg_no);
        temp=temp->next;
    }
}

int main(){
    int n;
    printf("enter number of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_node();
    }
    delete_front();
    display();
    insert_mid();
    display();
    return 0;
}