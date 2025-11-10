//book has title,author and price, sort it based on price using insertion sort and display using pointers;
#include<stdio.h>
#include<stdlib.h>

struct Book{
    char title[20];
    char author[20];
    float price;
};

void sort(struct Book *b[],int n){
    if(n<=1){
        return;
    }
    else{
        sort(b,n-1);
        struct Book *last=b[n-1];
        int j=n-2;
        while(j>=0 && b[j]->price>last->price){
            b[j+1]=b[j];
            j--;
        }
            b[j+1]=last;
    }      
}

void display(struct Book *b[],int n){
    for(int i=0;i<n;i++){
        printf("\nBook Details %d",i+1);
        printf("\nTitle: %s",b[i]->title);
        printf("\nAuthor: %s",b[i]->author);
        printf("\nPrice: %0.2f",b[i]->price);
    }
}
int main(){
    int n;
    printf("enter number of books: ");
    scanf("%d",&n);
    struct Book *b[n];
    for(int i=0;i<n;i++){
        b[i]=(struct Book *)malloc(sizeof(struct Book));
        printf("\nenter book details:");
        printf("\nenter title: ");
        scanf("%s",b[i]->title);
        printf("\nenter author: ");
        scanf(" %s",b[i]->author);
        printf("\nenter price: ");
        scanf(" %f",&b[i]->price);
    }
    sort(b,n);
    display(b,n);    
}
