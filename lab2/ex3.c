//memory allocation using array

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));

    if(arr==NULL){
        printf("memory not allocated");
        return 1;
    }

    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("array: ");
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }
    free(arr);
    return 0;

}