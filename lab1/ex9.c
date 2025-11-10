//read,multiply,add,magic square
#include<stdio.h>
#include<stdbool.h>

int main(){
    int m,n,a[10][10],b[10][10],s[10][10],p[10][10];
    printf("enter dimensions of A and B: ");
    scanf("%d%d",&m,&n);
    printf("enter A entries");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter B entries");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }

    int dsum=0,flag=1;
    for(int i=0;i<m;i++){
            dsum+=a[i][i];
        }

    for(int i=0;i<m;i++){
        int csum=0,rsum=0;
        for(int j=0;j<n;j++){
            rsum+=a[i][j];
            csum+=a[j][i];
        }
        if(rsum!=csum || csum!=dsum){
            flag=0;
            break;
        }
    }

    if(flag){
        printf("\nmagic square");
    }
    else{
        printf("\nnot a magic square");
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            s[i][j]=a[i][j]+b[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            p[i][j]=0;
            for(int k=0;k<n;k++){
                p[i][j]+=a[i][k]*b[k][j];
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

    printf("sum of A and B: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",s[i][j]);
        }
        printf("\n");
    }

    printf("product of A and B: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",p[i][j]);
        }
        printf("\n");
    }
    return 0;

}