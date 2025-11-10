/*shopping cart dynamic memory
product id,name,category,price
store in desc order using recursive bubble sort and display
*/

#include<stdio.h>
#include<stdlib.h>

struct Product{
    int ID;
    char name[25];
    char cat[25];
    float price;
};

void sorted(struct Product *p[], int n){
    if(n==1) return;
    else{
        for(int i=0;i<n-1;i++){
            if(p[i]->price<p[i+1]->price){
                struct Product *temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
        sorted(p,n-1);
    }
}

void display(struct Product *p[],int n){
    for(int i=0;i<n;i++){
        printf("\n Product details %d: ",i+1);
        printf("\n Product ID: %d: ",p[i]->ID);
        printf("\n Product name:  %s: ",p[i]->name);
        printf("\n Product category %s: ",p[i]->cat);
        printf("\n Product price %0.2f: ",p[i]->price);
    }
}
int main(){
    int n;
    printf("enter number of products: ");
    scanf("%d",&n);
    struct Product *p[n];
    for(int i=0;i<n;i++){
        p[i]=(struct Product*)malloc(sizeof(struct Product));
        printf("enter product details %d: ",i+1);
        printf("enter product id: ");
        scanf("%d",&p[i]->ID);
        printf("enter product name: ");
        scanf(" %s",p[i]->name);
        printf("enter product category: ");
        scanf(" %s",p[i]->cat);
        printf("enter product price: ");
        scanf(" %f",&p[i]->price);
    }
    sorted(p,n);
    display(p,n);
}