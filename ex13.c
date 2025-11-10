//find the row with maximum sum and then print the row

#include<stdio.h>
 
int main(){
    int sum[3];
    int arr[][3]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<3;i++){
        sum[i]=0;
        for(int j=0;j<3;j++){
            sum[i]+=arr[i][j];
        }
    }
    int max=sum[0];
    for(int i=0;i<3;i++){
        if(sum[i]>max){
            max=sum[i];
        }
    }
    printf("row with max sum: %d",max);
    return 0;
}