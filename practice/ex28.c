// expression tree evaluation
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isdigit()

// Expression tree node
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack of Node pointers
struct Node* stack[100];
int top = -1;

void push(struct Node* x) {
    stack[++top] = x;
}

struct Node* pop() {
    return stack[top--];
}

// Create a new tree node
struct Node* newNode(char value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Build expression tree from postfix
struct Node* buildTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {  // operand
            push(newNode(ch));
        } else {            // operator
            struct Node* root = newNode(ch);
            root->right = pop();
            root->left = pop();
            push(root);
        }
    }
    return pop();  // final tree root
}

// Evaluate the expression tree
int evaluate(struct Node* root) {
    if (root == NULL)
        return 0;

    // If leaf node (operand)
    if (isdigit(root->data))
        return root->data - '0';

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    switch (root->data) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

int main() {
    char postfix[] = "53+82-*";  // Example: (5+3)*(8-2)

    struct Node* root = buildTree(postfix);

    printf("Result = %d\n", evaluate(root));

    return 0;
}
