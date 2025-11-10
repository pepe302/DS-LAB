//find the largest element

#include<stdio.h>

int main(){
    int n,arr[10];
    printf("enter number of elements: ");
    scanf("%d", &n);
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    printf("the largest element is : %d", largest);

}