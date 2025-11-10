//check for matching parentheses in each expression using array based stack

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

void isMatching(char c){
    if(top!=-1){
        if(stack[top]=='('){
        if(c==')'){
            pop();
        }
    }
    else if(stack[top]=='['){
        if(c==']'){
            pop();
        }
    }
    else if(stack[top]=='{'){
        if(c=='}'){
            pop();
        }
    }
    else{
        printf("invalid character");
    }
    }
}

void isEmpty(){
    if(top!=-1){
        printf("stack not empty. Matching parentheses failed");
    }
    else{
        printf("stack empty. Matching parentheses successful");
    }
}
int main(){
    char str[max];
    printf("enter expression: ");
    fgets(str,max,stdin);
    str[strcspn(str,"\n")]='\0';
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            push(str[i]);
        }
        else{
            isMatching(str[i]);
        }
    }
    isEmpty();
    return 0;
}