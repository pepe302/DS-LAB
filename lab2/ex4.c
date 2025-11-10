//smallest element function using pointers

#include<stdio.h>
#include<stdlib.h>

void smallest(int *arr, int n){
    int smallest=*arr;
    for(int i=0;i<n;i++){
        if(*(arr+i)<smallest){
            smallest=*(arr+i);
        }
    }
    printf("\nsmallest element in array : %d", smallest);
}

int main(){
    int n,*arr;
    printf("enter number of elements in the array: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("array: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    smallest(arr,n);
    return 0;
}