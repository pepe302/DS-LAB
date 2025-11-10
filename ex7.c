/*
Menu driven c program
 Make a library database of books,
  with variables int id, string title, author , float price. 
  1) Functions for add and display 
  2) Binary search using recursion
  3) search by title
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    int id;
    char title[25];
    char author[25];
    float price;
};

int count=0;

void add(struct Book *b[]){
    if(count>=30){
        printf("library is full");
        return;
    }
    b[count]=(struct Book *)malloc(sizeof(struct Book));
    printf("\nenter book details %d: ",count+1);
        printf("\nenter ID: ");
        scanf(" %d",&b[count]->id);
        printf("\nenter title: ");
        scanf(" %s",b[count]->title);
        printf("\nenter author: ");
        scanf(" %s",b[count]->author);
        printf("\nenter price: ");
        scanf(" %f",&b[count]->price);
        count++;
}


void display(struct Book *b[]){
    for(int i=0;i<count;i++){
        printf("\nBook Details %d",i+1);
        printf("\nID: %d",b[i]->id);
        printf("\nTitle: %s",b[i]->title);
        printf("\nAuthor %s",b[i]->author);
        printf("\nPrice: %0.2f",b[i]->price);
    }
}

void sortBooks(struct Book *b[]){
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-i-1;j++){
            if(strcmp(b[j]->title,b[j+1]->title)>0){
                struct Book *temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
}


int search(struct Book *b[],int low,int high,char str[]){
    if(low>high) return -1;
    int mid=(low+high)/2;
    int cmp=strcmp(str,b[mid]->title);
    if(cmp==0) return mid;
    else if(cmp<0) return search(b,low,mid-1,str);
    else return search(b,mid+1,high,str);
}

int main(){
    int op;
    struct Book*b[30];
    do{
        printf("\nmenu details: ");
        printf("\n1.Add books");
        printf("\n2.display books");
        printf("\n3.search for book by title");
        printf("\n4.exit");
        printf("\nenter choice: ");
        scanf("%d",&op);

        switch(op){
            case 1:
                add(b);
                break;
            
            case 2: 
                display(b);
                break;
            
            case 3: {
                char str[25];
                printf("\nenter title to search: ");
                scanf(" %s",str);
                sortBooks(b);
                int idx=search(b,0,count-1,str);
                if(idx==-1){
                    printf("book not found");
                }
                else{
                    printf("\nbook found:\n");
                    printf("ID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\n",
                    b[idx]->id, b[idx]->title, b[idx]->author, b[idx]->price);
                }
                break;
            }
            case 4: 
                printf("exiting.. ");
                break;
            default:
                printf("invalid choice");
                break;
        }

    }while(op!=4);
    return 0;
}