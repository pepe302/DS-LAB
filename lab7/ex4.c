//evaluate postfix expression using linked list based stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define max 25

struct Node{
    float data;
    struct Node *next;
}*top=NULL;

void push(float c){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=c;
    newNode->next=top;
    top=newNode;
}

float pop(){
    if(top!=NULL){
        float c=top->data;
        struct Node *temp=top;
        top=top->next;
        free(temp);
        return c;
    }
    return '\0';
}

int isOperand(char c){
    if(c>='0' && c<='9') return 1;
    else return 0;
}

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' ||c=='/'||c=='^') return 1;
    else return 0;
}

int op(char c){
    if(c=='+') return 1;
    if(c=='-') return 2;
    if(c=='*') return 3;
    if(c=='/') return 4;
    if(c=='^') return 5;
    else return 0;
}

void peek(){
    if(top!=NULL){
        printf("\nevaluation: %0.2f",top->data);
    }
}
void evaluate(char str[]){
    for(int i=0;i<strlen(str);i++){
        if(isOperand(str[i])){
            push(str[i]-'0');
        }
        else if(isOperator(str[i])){
            float op1=pop();
            float op2=pop();
            float result;
            switch(str[i]){
                case '+': result=op2+op1;break;
                case '-': result=op2-op1;break;
                case '*': result=op2*op1;break;
                case '/': result=op2/op1;break;
                case '^': result=pow(op2,op1);break;
            }
            push(result);
        }
    }
}

int main(){
    char postfix[max];
    printf("enter postfix expression: ");
    fgets(postfix,max,stdin);
    postfix[strcspn(postfix,"\n")]='\0';
    printf("\npostfix expression: %s",postfix);
    evaluate(postfix);
    peek();
    return 0;
}