//singly linked lists operations
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void create_node(){
    struct Node *new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("memory not allocated");
        return;
    }

    printf("\nenter element: ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;

    if(head==NULL){
        head=new_node;
        return;
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    
}

void display(){
    if(head==NULL){
        printf("empty list");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");

}

void delete_node(){
    struct Node *temp,*temp2;
    int ele;

    if(head==NULL){
        printf("empty list");
        return;
    }

    printf("enter element to delete: ");
    scanf("%d",&ele);

    if(head->data==ele){
        temp=head;
        head=head->next;
        free(temp);
        return;
    }
    temp=head;
    while(temp->next!=NULL && temp->next->data!=ele){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("element not found");
        return;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}

void insert_before(){
    struct Node *temp,*newNode;
    int ele;
    newNode=(struct Node *)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }

    printf("enter element to insert:");
    scanf("%d",&newNode->data);
    printf("enter element to insert before: ");
    scanf("%d",&ele);

    temp=head;
    if(head->data==ele){
        temp=head;
        head=newNode;
        newNode->next=temp;
    }

    while(temp!=NULL && temp->next!=NULL && temp->next->data!=ele){
        temp=temp->next;
    }
    if(temp==NULL ||temp->next==NULL){
        printf("element does not exist");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}

void insert_after(){
    struct Node *temp,*newNode;
    int ele;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory not allocated");
        return;
    }
    printf("enter element to insert:");
    scanf("%d",&newNode->data);
    printf("enter element to insert after: ");
    scanf("%d",&ele);

    temp=head;
    while(temp!=NULL && temp->data!=ele){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("element not found");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void reverse_list(){
    struct Node *temp=head,*next=NULL,*prev=NULL;
    if(head==NULL){
        printf("empty list");
        return;
    }
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}

void sort(){
    struct Node *i,*j;
    int temp;
    if(head==NULL){
        printf("empty list");
        return;
    }
    
    for(i=head;i->next!=NULL;i++){
        for(j=i->next;j!=NULL;j++){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    
}

void delete_alt(){
    struct Node *temp=head,*delete_node;
    if(head==NULL){
        printf("empty list");
        return;
    }
    
    while(temp!=NULL && temp->next!=NULL){
        delete_node=temp->next;
        temp->next=delete_node->next;
        free(delete_node);
        temp=temp->next;
    }
}

void insert_ele(){
    struct Node *temp=head,*newNode,*prev=NULL;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    if(head==NULL){
        printf("empty list");
        return;
    }
    printf("enter element to be inserted");
    scanf("%d",&newNode->data);
    if (head == NULL || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
\
    temp = head;
    while (temp != NULL && temp->data < newNode->data) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = newNode;
    newNode->next = temp;

}
int main(){
    int choice;
    do{
        printf("\nMenu: ");
        printf("\n1.create node/list");
        printf("\n2.delete an element");
        printf("\n3.traverse and display");
        printf("\n4.insert element before another element");
        printf("\n5.insert element after another element");
        printf("\n6.reverse list");
        printf("\n7.sort in ascending order");
        printf("\n8.delete alternating node");
        printf("\n9.insert element into sorted list");
        printf("\n10.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                    create_node();
                    break;
            case 2:
                    delete_node();
                    break;
            case 3: 
                    display();
                    break;
            case 4: 
                    insert_before();
                    break;
            case 5: 
                    insert_after();
                    break;
            
            case 6: 
                    reverse_list();
                    break;

            case 7: 
                    sort();
                    break;
            case 8:     
                    delete_alt();
                    break;

            case 9:
                    insert_ele();
                    break;
            case 10: 
                    printf("\nexiting..");
                    exit(0);
            default: 
                    printf("invalid choice");
                    break;
        }
    }while(choice!=10);
    return 0;
}