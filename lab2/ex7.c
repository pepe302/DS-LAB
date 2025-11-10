//tower of hanoi using recursion for n disks
#include<stdio.h>

int main(){
    int n;
    printf("enter number of disks");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}

void toh(int n,char start,char finish,char temp){
    if(n==0){
        return;
    }
    else{
        toh(n-1,start,temp,finish);
        printf("\nmove disk %d from %c to %c",n,start,finish);
        toh(n-1,temp,finish,start);
    }
}