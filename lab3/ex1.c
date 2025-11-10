//read string,struct

#include<stdio.h>

struct Student{
    char Name[50];
    int rno;
};

int main(){
    struct Student s1={"Atisha",101};
    struct Student *p=&s1;
    printf("Name: %s", p->Name);
    printf("\nrno: %d", p->rno);
}
