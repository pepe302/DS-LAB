/*structures book data ;
 name, author, price, 
 sort the data by price using recursive bubble sort display in ascending order of price
*/

#include<stdio.h>
#include<stdlib.h>

struct Book{
    char title[25];
    char author[25];
    float price;
};

void sort(struct Book *b[],int n){
    if(n==1) return;
    else{
        for(int i=0;i<n-1;i++){
            if(b[i]->price>b[i+1]->price){
                struct Book *temp=b[i];
                b[i]=b[i+1];
                b[i+1]=temp;
            }
        }
        sort(b,n-1);
    }
}
void display(struct Book *b[],int n){
    for(int i=0;i<n;i++){
        printf("\nBook Details %d",i+1);
        printf("\nTitle: %s",b[i]->title);
        printf("\nAuthor %s",b[i]->author);
        printf("\nPrice: %0.2f",b[i]->price);
    }
}
int main(){
    int n;
    printf("enter number of books: ");
    scanf("%d",&n);
    struct Book *b[n];
    for(int i=0;i<n;i++){
        b[i]=(struct Book*)malloc(sizeof(struct Book));
        printf("\nbook details %d: ",i+1);
        printf("\nenter title: ");
        scanf(" %s",b[i]->title);
        printf("\nenter author: ");
        scanf(" %s",b[i]->author);
        printf("\nenter price: ");
        scanf(" %f",&b[i]->price);
    }
    sort(b,n);
    display(b,n);
    return 0;
}