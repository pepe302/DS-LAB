// array based stack to check palindrome

#include<stdio.h>
#include<string.h>

#define max 25

int top=-1;
char stack[max];

void push(char c){
    if(top<max-1){
        stack[++top]=c;
    }
}

char pop(){
    if(top!=-1){
        return stack[top--];
    }
    return '\0';
}

void isPal(char str[]){
    for(int i=0;i<strlen(str);i++){
        push(str[i]);
    }
    char rev[max];
    rev[strlen(str)]='\0';
    for(int i=0;i<strlen(str);i++){
        rev[i]=pop();
    }
    
    int pal=strcmp(str,rev);
    if(pal==0){
        printf("palindrome");
    }
    else{
        printf("not a palindrome");
    }
}

int main(){
    char str[max];
    printf("enter string: ");
    fgets(str,max,stdin);
    str[strcspn(str,"\n")]='\0';
    isPal(str);
    return 0;
}