//transpose of a sparse matrix
#include<stdio.h>

#define max 100

struct Sparse{
    int row,col,val;
};

void transpose(struct Sparse a[],struct Sparse b[]){
    int i,j,n;
    n=a[0].val;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=n;


    int k=1;

    for(int i=0;i<a[0].col;i++){
        for(int j=1;j<=n;j++){
            if(a[j].col==i){
                b[k].row=a[j].col;
                b[k].col=a[j].row;
                b[k].val=a[j].val;
                k++;
            }
        }
    }
}

int main(){
    struct Sparse a[max], b[max];
    int m,n,num;
    printf("enter number of rows and cols: ");
    scanf("%d%d",&m,&n);

    printf("enter number of non zero elements: ");
    scanf("%d",&num);

    a[0].row=m;
    a[0].col=n;
    a[0].val=num;

    printf("enter row,col and non-zero elements: ");
    for(int i=0;i<=num;i++){
        scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].val);
    }

    transpose(a,b);

    printf("transpose in 3 tuple form: ");
    printf("row  col  val\n");
    for(int i=0;i<=b[0].val;i++){
        printf("%d  %d  %d\n",b[i].row,b[i].col,b[i].val);
    }
    return 0;
}