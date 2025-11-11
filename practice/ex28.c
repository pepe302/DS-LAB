#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit()

// Structure for tree node
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for nodes
struct Stack {
    int top;
    struct Node* arr[50];
};

// Create a new tree node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push node onto stack
void push(struct Stack* s, struct Node* node) {
    s->arr[++(s->top)] = node;
}

// Pop node from stack
struct Node* pop(struct Stack* s) {
    if (s->top == -1) return NULL;
    return s->arr[(s->top)--];
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Build expression tree from postfix
struct Node* buildTree(char postfix[]) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isspace(ch)) continue; // Skip spaces

        // If operand, create node and push
        if (isdigit(ch)) {
            struct Node* newNode = createNode(ch);
            push(&s, newNode);
        }
        // If operator, pop two nodes, make them children
        else if (isOperator(ch)) {
            struct Node* newNode = createNode(ch);
            newNode->right = pop(&s);
            newNode->left = pop(&s);
            push(&s, newNode);
        }
    }

    // Final node is root
    return pop(&s);
}

// Inorder traversal (with parentheses for clarity)
void inorder(struct Node* root) {
    if (root == NULL) return;
    if (isOperator(root->data)) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (isOperator(root->data)) printf(")");
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

// Evaluate expression tree
int evaluate(struct Node* root) {
    if (root == NULL) return 0;

    // If it's a leaf node (operand)
    if (!isOperator(root->data))
        return root->data - '0';  // convert char digit to int

    // Evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Apply operator
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        case '^': {
            int res = 1;
            for (int i = 0; i < rightVal; i++) res *= leftVal;
            return res;
        }
    }
    return 0;
}

// Main function
int main() {
    char postfix[50];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = buildTree(postfix);

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\nEvaluated result: %d\n", evaluate(root));

    return 0;
}
