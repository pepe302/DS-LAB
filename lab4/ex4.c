//interleave two lists 
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
        
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("enter element: ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
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
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL");
}

struct Node *merge(struct Node *head1, struct Node *head2){
struct Node dummy;  // temporary dummy node
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        // attach one node from list1
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;

        // attach one node from list2
        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
    }

    // attach remaining nodes (if any list is longer)
    if (head1 != NULL) {
        tail->next = head1;
    } else if (head2 != NULL) {
        tail->next = head2;
    }

    return dummy.next; // return new head

}
int main(){
    struct Node *head1=NULL,*head2=NULL,*merged=NULL;
    printf("enter list 1: ");
    head1=create_list();
    printf("enter list 2: ");
    head2=create_list();
    printf("\nX1=");
    display(head1);
    printf("\nX2=");
    display(head2);
    merged=merge(head1,head2);
    display(merged);
    return 0;
}