//using DLL find polynomial addition
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff,expo;
    struct Node *next,*prev;
};

void create_node(struct Node **head,int coeff,int expo){
    struct Node*temp,*newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->coeff=coeff;
    newNode->expo=expo;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
    }
    temp->next=newNode;
    newNode->prev=temp;
}

struct Node *addPoly(struct Node *head1, struct Node *head2){
    struct Node *head3=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->expo==head2->expo){
            create_node(&head3,head1->coeff+head2->coeff,head1->expo);
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->expo>head2->expo){
            create_node(&head3,head1->coeff,head1->expo);
            head1=head1->next;
        }
        else if(head1->expo<head2->expo){
            create_node(&head3,head2->coeff,head2->expo);
            head2=head2->next;
        }
    }
        while(head1!=NULL){
            create_node(&head3,head1->coeff,head1->expo);
            head1=head1->next;
        }
        while(head2!=NULL){
            create_node(&head3,head2->coeff,head2->expo);
            head2=head2->next;
        }
    
    return head3;
}

void display(struct Node *head){
    if(head==NULL){
        printf("no polynomial/cancelled out");
        return;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            printf("%dx^%d+ ",temp->coeff,temp->expo);
            temp=temp->next;
        }
        printf("%dx^%d ",temp->coeff,temp->expo);
    }
}

int main(){
    struct Node *head1=NULL,*head2=NULL,*result=NULL;
    int n,co,exp;
    printf("\nenter number of terms in P1: ");
    scanf("%d",&n);
    printf("\nenter coeff and expo into polynomial: ");
    for(int i=0;i<n;i++){
        scanf("%d %d",&co,&exp);
        create_node(&head1,co,exp);
    }
    
    
    printf("\nenter number of terms in P2: ");
    scanf("%d",&n);
    printf("\nenter coeff and expo into polynomial: ");
    for(int i=0;i<n;i++){
        scanf("%d %d",&co,&exp);
        create_node(&head2,co,exp);
    }
    printf("\npolynomial 1: ");
    display(head1);
    printf("\npolynomial 2: ");
    display(head2);

    printf("\nsum of the two polynomials: ");
    result=addPoly(head1,head2);
    display(result);
    return 0;
}