/*Write a C program to create an array of structures using dynamic memory allocation.
Each structure should store the details of a student with the following fields:
rollNo (integer),name (string),marks (float)
Use malloc() to dynamically allocate memory for an initial number of students (say, n).
Implement separate functions to:
Read student details (readStudents()).
Display student details (displayStudents()).
Later, use realloc() to increase the size of the array to store more students, and read the new entries.
Display all student records again after adding the new entries.*/

#include<stdio.h>
#include<stdlib.h>

struct Student{
    int roll;
    char name[25];
    float marks;
};

void readStud(struct Student *s,int n){
    for(int i=0;i<n;i++){
        printf("\nenter name: ");
        scanf("%s",s[i].name);
        printf("\nenter roll number: ");
        scanf("%d",&s[i].roll);
        printf("\nenter marks: ");
        scanf("%f",&s[i].marks);
    }
}

void display(struct Student *s,int n){
    for(int i=0;i<n;i++){
        printf("Name: %s\nRoll: %d\nMarks:%0.2f\n",s[i].name,s[i].roll,s[i].marks);
    }
}

int main(){
    struct Student *stud;
    int n,new_n;
    printf("\nenter number of students: ");
    scanf("%d",&n);
    stud=(struct Stuudent *)calloc(n,sizeof(struct Student));
    readStud(stud,n);
    display(stud,n);
    printf("\nenter new total number of students: ");
    scanf("%d",&new_n);
    stud=(struct Student *)realloc(stud,new_n*sizeof(struct Student));
    printf("\nenter details for new students: ");
    readStud(stud+n,new_n-n);
    display(stud,new_n);
    free(stud);
    return 0;
}