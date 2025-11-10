//linear search

#include<stdio.h>

int main(){
    int n,arr[10],key,found=0;
    printf("enter number of elements: ");
    scanf("%d", &n);
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("enter element to be searched: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("element found at %d",i);
            found=1;
        }
    }
    if(found==0){
        printf("element does not exist");
    }
    return 0;

}