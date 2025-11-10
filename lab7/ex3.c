#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 25

struct Node {
    struct Node *next;
    char data;
} *top = NULL;

void push(char c) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if(top == NULL) return '\0';
    char c = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return c;
}

char peek() {
    if(top == NULL) return '\0';
    return top->data;
}

int isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int checkPrec(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

void convertToPostfix(char in[]) {
    char post[max];
    int j = 0;

    for(int i = 0; i < strlen(in); i++) {
        if(isOperand(in[i])) {
            post[j++] = in[i];
        }
        else if(in[i] == '(') {
            push(in[i]);
        }
        else if(in[i] == ')') {
            while(top != NULL && peek() != '(') {
                post[j++] = pop();
            }
            pop(); 
        }
        else if(isOperator(in[i])) {
            while(top != NULL && checkPrec(peek()) >= checkPrec(in[i])) {
                post[j++] = pop();
            }
            push(in[i]);
        }
    }

    while(top != NULL) {
        post[j++] = pop();
    }

    post[j] = '\0';
    printf("\nPostfix expression: %s\n", post);
}

int main() {
    char infix[max];
    printf("Enter infix expression: ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    printf("Infix expression: %s\n", infix);
    convertToPostfix(infix);
    return 0;
}
