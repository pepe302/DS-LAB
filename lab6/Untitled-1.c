#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[25];
int top=-1;

void push(char c){
    if(top!=24){
        stack[++top]=c;
    }
    else{
        return;
    }
}

char pop(char str[]){
    if(top!=-1){
        
    }
}

int main(){
    char str[25];
    printf("enter string: ");
    gets(str);
    int m=strlen(str);
    for(int i=0;i<m;i++){
        push(str[i]);
    }
}
