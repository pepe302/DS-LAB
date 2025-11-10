//evaluate the polynomial by inputting x

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int coeff, expo;
    struct Node *next;
};

void create_node(struct Node **head,int coeff, int expo){
    struct Node *newNode,*temp;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->coeff=coeff;
    newNode->expo=expo;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
    }
    temp->next=newNode;
}

void display(struct Node*head){
    if(head==NULL){
        printf("no polynomial");
        return;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            printf("%dx^%d + ",temp->coeff,temp->expo);
            temp=temp->next;
        }
        printf("%dx^%d ",temp->coeff,temp->expo);
    }
}

 void evaluate(struct Node *head1,int x){
    struct Node *temp=head1;
    int sum=0;
    while(temp!=NULL){
        sum+=temp->coeff*pow(x,temp->expo);
        temp=temp->next;
    }
    printf("sum of polynomial when x is %d: %d",x,sum);
    
}


int main(){
    struct Node *head1=NULL;
    int n,co,ex,x;
    printf("\nenter number of terms in polynomial: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nenter coeff and expo: ");
        scanf("%d%d",&co,&ex);
        create_node(&head1,co,ex);
    }
    printf("\npolynomial is: ");
    display(head1);

    printf("\nenter value of X: ");
    scanf("%d",&x);
    evaluate(head1,x);
    return 0;
}