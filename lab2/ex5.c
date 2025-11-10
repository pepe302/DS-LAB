//recursive selection sort using pointers

#include<stdio.h>
#include<stdlib.h>

int rec_sel(int *arr,int i, int n){
    if(i>=n-1)
        return 0;
    else{
        int min=i;
        for(int j=i+1;j<n;j++){
                if(*(arr+j)<*(arr+min))
                    min=j;
            }

            if(min!=i){
                int temp=*(arr+i);
                *(arr+i)=*(arr+min);
                *(arr+min)=temp;
            }

            return rec_sel(arr,i+1,n);
        }
        
    } 
    


int main(){
    int *arr,n;
    printf("enter number of elements: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*(sizeof(int)));
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("array before sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }
    rec_sel(arr,0,n);
    printf("\narray after sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }
    return 0;
}