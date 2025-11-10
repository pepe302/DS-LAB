/*Insertion at beginning
 identify if the entered char is palindrome or not using 
 forward and reverse traversal
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char letter;
    struct Node *next,*prev;
}*head=NULL;

void create_node(){
    struct Node *newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter character into string: ");
    scanf(" %c",&newNode->letter);
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

 void forward_trav(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%c",temp->letter);
        temp=temp->next;
    }
}

void rev_trav(){
    printf("\n");
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%c",temp->letter);
        temp=temp->prev;
    }
}

int main(){
    char str[20];
    printf("enter the string: ");
    gets(str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        create_node();
    }
    forward_trav();
    rev_trav();
    return 0;
}
