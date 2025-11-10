//binary search
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
    int f=0,l=n-1;
    while(f<=l){
        int mid=(f+l)/2;
        if(arr[mid]==key){
            found=1;
            printf("element has been found");
            break;
        }
        else if(key>arr[mid]){
            f=mid+1;
        }
        else{
            l=mid-1;
        }
    }
    if(found==0){
        printf("element missing");
    }
    return 0;
}