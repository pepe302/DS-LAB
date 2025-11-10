//student structure

#include<stdio.h>
#include<stdlib.h>


struct Student{
    char name[25];
    char grade;
    int rno;
};

void display(struct Student s[], int num){
    for(int i=0;i<num;i++){
        printf("\nStudent details %d:", i+1);
        printf("\n%s\n%d\n%c",s[i].name,s[i].rno,s[i].grade);
    }
}

void sort(struct Student s[], int num){
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(s[j].rno>s[j+1].rno){
            struct Student temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
        }
        }
        
    }
}

int main(){
    int num;
    printf("enter number of students: ");
    scanf("%d",&num);
    struct Student s[num];
    for(int i=0;i<num;i++){
        printf("enter student details %d",i+1);
        printf("\nenter name: ");
        scanf("%s",s[i].name);
        printf("\nenter rno: ");
        scanf("%d",&s[i].rno);
        printf("\nenter grade: ");
        scanf(" %c",&s[i].grade);
    }
    
    sort(s,num);
    display(s,num);
    return 0;
}