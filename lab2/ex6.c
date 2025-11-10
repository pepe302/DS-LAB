//read,display,multiply two matrices using pointers

#include<stdio.h>
#include<stdlib.h>

void read(int **arr,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void display(int **arr,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf(" %d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
}

void multiply(int **a, int **b, int ** p,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            p[i][j]=0;
            for(int k=0;k<c;k++){
                p[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

int main(){
    int r,c, **a, **b,**p;
    printf("enter dimensions: ");
    scanf("%d%d", &r,&c);

    a=(int **)malloc(r*(sizeof(int *)));
    for(int i=0;i<r;i++){
        a[i]=(int *)malloc(c*(sizeof(int)));
    }

    b=(int **)malloc(r*(sizeof(int *)));
    for(int i=0;i<r;i++){
        b[i]=(int *)malloc(c*(sizeof(int)));
    }
    
    p=(int **)malloc(r*(sizeof(int *)));
    for(int i=0;i<r;i++){
        p[i]=(int *)malloc(c*(sizeof(int)));
    }

    printf("enter matrix A: ");
    read(a,r,c);
    printf("enter matrix B:");
    read(b,r,c);

    printf("matrix A: \n");
    display(a,r,c);

    printf("matrix B: \n");
    display(b,r,c);

    printf("Matrix product: \n");
    multiply(a,b,p,r,c);
    display(p,r,c);
    return 0;
}