//max of two matrices

#include<stdio.h>

int main(){
    int m,n,a[10][10],b[10][10],c[10][10];
    printf("enter dimensions of A and B: ");
    scanf("%d%d",&m,&n);
    printf("enter A entries: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter B entries: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]>=b[i][j]){
                c[i][j]=a[i][j];
            }
            else{
                c[i][j]=b[i][j];
            }
        }
    }
    printf("matrix A: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    printf("matrix B: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",b[i][j]);
        }
        printf("\n");
    }
    printf("matrix C: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",c[i][j]);
        }
        printf("\n");
    }
}