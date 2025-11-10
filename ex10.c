/*polynomial addition SLL*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int expo;
    struct Node *next;
};

void create_term(struct Node **head1){
    struct Node *newTerm,*temp;
    newTerm=(struct Node*)malloc(sizeof(struct Node));
    printf("enter coefficient and exponent(in desc order): ");
    scanf("%d%d",&newTerm->coeff,&newTerm->expo);
    newTerm->next=NULL;
    if(*head1==NULL){
        *head1=newTerm;
    }
    else{
        temp=*head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newTerm;
    }
}

void insert_result(struct Node **res,int coeff,int expo){
    if(coeff==0)return;
    struct Node*newTerm=(struct Node*)malloc(sizeof(struct Node));
    newTerm->coeff=coeff;
    newTerm->expo=expo;
    newTerm->next=NULL;
    if(*res==NULL){
        *res=newTerm;
    }
    else{
        struct Node *temp=*res;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newTerm;
    }
}

struct Node *polyAdd(struct Node *head1,struct Node *head2){
    struct Node *res=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->expo==head2->expo){
            insert_result(&res,head1->coeff+head2->coeff,head1->expo);
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->expo>head2->expo){
            insert_result(&res,head1->coeff,head1->expo);
            head1=head1->next;
        }
        else{
            insert_result(&res,head2->coeff,head2->expo);
            head2=head2->next;
        
        }

        while(head1!=NULL){
            insert_result(&res,head1->coeff,head1->expo);
            head1=head1->next;
        }

         while(head2!=NULL){
            insert_result(&res,head2->coeff,head2->expo);
            head2=head2->next;
        }
    }
    return res;
}
void display(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%dx^%d ",temp->coeff,temp->expo);
        temp=temp->next;
    }
    printf("0");
}


int main(){
    struct Node *head1=NULL,*head2=NULL,*result=NULL;
    int m,n;
    printf("enter number of terms in poly1: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        create_term(&head1);
    }
    printf("enter number of terms in pol2: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_term(&head2);
    }
    printf("polynomial 1: ");
    display(head1);
    printf("\npolynomial 2: ");
    display(head2);
    printf("\nresult: ");
    result=polyAdd(head1,head2);
    display(result);
    return 0;
}