/*Doubly Linked List stores the Price of Products purchased.
 A) Calculate the total price of the bill 
 B) Display the list before and after appending the total at the end of the list*/

 #include<stdio.h>
 #include<stdlib.h>

 struct Node{
    int data;
    struct Node *next,*prev;
 }*head=NULL;

void create_node(){
    struct Node *newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter product price: ");
    scanf("%d",&newNode->data);
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

void display(){
    if(head==NULL){
        printf("empty list");
        return;
    }
    else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("=");
    }
}

void total(){
    struct Node *temp;
    if(head==NULL){
        printf("empty list");
        return;
    }else{
        temp=head;
        int sum=0;
        while(temp!=NULL){
            sum+=temp->data;
            temp=temp->next;
        }
        display();
        printf("%d",sum);
    }

}
 int main(){
    int n;
    struct Node *list;
    printf("enter number of products purchased: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_node();
    }
    printf("\nlist before total: ");
    display();
    printf("\nlist after total: ");
    total();
    return 0;
 }