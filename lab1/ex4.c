//bubble sort

#include<stdio.h>

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){   //5 4 3 2 1      
            if(arr[j]>arr[j+1]){    //4 5 3 2 1        
            int temp=arr[j];        //4 3 5 2 1 
            arr[j]=arr[j+1];        //4 3 2 5 1
            arr[j+1]=temp;          // 4 3 2 1 5 repeat but n-1
            }
        }
    }
}

int main(){
    int n,arr[10];
    printf("enter number of elements: ");
    scanf("%d", &n);
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("array before sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }

    bubble_sort(arr,n);
    
    printf("\narray after sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    
    return 0;
}