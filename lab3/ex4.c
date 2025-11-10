//student with pointers

#include<stdio.h>
#include<stdlib.h>

struct Student{
    int rno;
    float marks;
    char name[25];
};

void display(struct Student *s[], int n){
    printf("Student details: ");
    for(int i=0;i<n;i++){
        printf("\nName: %s\nrno: %d\nmarks: %0.2f\n", s[i]->name,s[i]->rno,s[i]->marks);
    }   
}

void highest(struct Student *s[], int n){
    struct Student *topper=s[0];
    for(int i=1;i<n;i++){
        if(s[i]->marks>topper->marks){
            topper=s[i];
        }
    }
    printf("%s got the highest marks",topper->name);
}
int main(){
    int n;
    printf("enter the number of students: ");
    scanf("%d",&n);
    struct Student *s[n];

    for(int i=0;i<n;i++){
        s[i]=(struct Student*)malloc(sizeof(struct Student));
        printf("enter student details: ");
        printf("\nenter name:");
        scanf("%s",s[i]->name);
        printf("\nenter rno:");
        scanf("%d",&s[i]->rno);
        printf("\nenter marks:");
        scanf("%f",&s[i]->marks);
    }

    display(s,n);
    highest(s,n);
    return 0;
}