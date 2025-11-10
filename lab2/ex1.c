//access and modify a variable using pointer

#include<stdio.h>

int main(){
int x=10;
int *p=&x;
printf("\nvalue of x: %d",x);
printf("\nvalue of x through p: %d",*p);
*p=20;
printf("\nnew value of x: %d",x);
return 0;
    
}