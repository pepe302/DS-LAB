//selection sort

#include<stdio.h>

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;                     //5 4 3 2 1 min is the index
        for(int j=i+1;j<n;j++){      // 1 4 3 2 5
            if(arr[j]<arr[min]){     // 1 2 3 4 5
                min=j;
            }
        }    
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
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

    selection_sort(arr,n);
    
    printf("\narray after sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    
    return 0;
}
