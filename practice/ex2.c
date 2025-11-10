//enter number of patients for n days, find min number of patients, display all patients with days

#include<stdio.h>
#include<stdlib.h>

void sort(int *p,int n){
    if(n==1){
        return;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(p[i]>p[i+1]){
                int temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
        sort(p,n-1);
    }
}

void disp_min(int *p,int n){
    int min=p[0];
    int day=1;
    for(int i=1;i<n;i++){
        if(p[i]<min){
            min=p[i];
            day=i+1;
        }
    }
    printf("\nDay with minimum patients: %d=%d patients",day,min);
}

void display(int *p, int n){
    for(int i=0;i<n;i++){
        printf("\nday %d: %d",i+1,p[i]);
    }
}

int main(){
    int n;
    printf("enter number of days: ");
    scanf("%d", &n);
    int *p=(int *)malloc(n*sizeof(int));
    printf("enter number of patients for each day: ");
    for(int i=0;i<n;i++){
        printf("\nDay %d: ",i+1);
        scanf("%d",&p[i]);
    }
    disp_min(p,n);
    sort(p,n);
    
    display(p,n);
    return 0;
}