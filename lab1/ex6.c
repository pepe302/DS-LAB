//insertion sort

#include<stdio.h>

void insertion_sort(int arr[], int n){ 
     for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

    insertion_sort(arr,n);
    
    printf("\narray after sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    
    return 0;
}
