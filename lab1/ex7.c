//number of swaps made in bubble sort, selection sort, insertion sort
#include<stdio.h>

void bubble_sort(int arr[], int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
            }
        }
    }
    printf("swaps in bubble sort: %d",count);
}

void selection_sort(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
            count++;
           }
    }
    printf("\nswaps in selection sort: %d",count);
}

void insertion_sort(int arr[],int n){
    int count=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
            count++;
        }
        arr[j+1]=key;
    }
    printf("\nswaps in insertion sort: %d",count);
}


int main(){
    int arr[10],n;
    printf("enter number of array elements: ");
    scanf("%d",&n);
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    int arr1[10],arr2[10],arr3[10];
    for(int i=0;i<n;i++){
        arr1[i]=arr[i];
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    }
    bubble_sort(arr1,n);
    selection_sort(arr2,n);
    insertion_sort(arr3,n);
    return 0;
}