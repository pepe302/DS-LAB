//merge two sorted linked lists into a new sorted list 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *create_list(){
    struct Node *newNode,*temp=NULL,*head=NULL;
    int choice;
    do{
        newNode=(struct Node *)malloc(sizeof(struct Node));
        printf("enter element: ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }

    printf("1 to continue | 0 to exit: ");
    scanf("%d", &choice);
    }while(choice==1);
    return head;
}

void display(struct Node *head){
    while(head!=NULL){
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL");
}

struct Node * merge_sorted(struct Node *head1, struct Node *head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    struct Node*result=NULL;
    if(head1->data<=head2->data){
        result=head1;
        result->next=merge_sorted(head1->next,head2);
    }else{
        result=head2;
        result->next=merge_sorted(head1,head2->next);
    }
    return result;
}

int main(){
    struct Node *head1=NULL,*head2=NULL,*merged=NULL;
    printf("\nenter elements into X1: ");
    head1=create_list();
    printf("\nenter elements into X2: ");
    head2=create_list();
    printf("X1: \n");
    display(head1);
    printf("\nX2: \n");
    display(head2);
    merged=merge_sorted(head1,head2);
    printf("merged sorted list: \n");
    display(merged);
    return 0;
}
