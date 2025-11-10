#include <stdio.h>
#include <stdlib.h>
#define max 50

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order creation
struct Node *queue[max];
int front = -1, rear = -1;

void enqueue(struct Node *data) {
    if (rear == max - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = data;
}

struct Node *dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Function to create tree level-wise
struct Node *createTree() {
    int data;
    printf("Enter root data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    struct Node *root = createNode(data);
    enqueue(root);

    while (front <= rear) {
        struct Node *curr = dequeue();
        int leftData, rightData;

        printf("Enter left child of %d (-1 for no node): ", curr->data);
        scanf("%d", &leftData);
        if (leftData != -1) {
            curr->left = createNode(leftData);
            enqueue(curr->left);
        }

        printf("Enter right child of %d (-1 for no node): ", curr->data);
        scanf("%d", &rightData);
        if (rightData != -1) {
            curr->right = createNode(rightData);
            enqueue(curr->right);
        }
    }
    return root;
}

//////////////////////////////////////////////////////////
// i) Inorder Traversal (Iterative)
void inorder(struct Node *root) {
    struct Node *stack[max];
    int top = -1;
    struct Node *curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

//////////////////////////////////////////////////////////
// ii) Postorder Traversal (Iterative)
void postorder(struct Node *root) {
    if (root == NULL) return;
    struct Node *stack1[max], *stack2[max];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node *curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left) stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

//////////////////////////////////////////////////////////
// iii) Preorder Traversal (Iterative)
void preorder(struct Node *root) {
    if (root == NULL) return;
    struct Node *stack[max];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node *curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
}

//////////////////////////////////////////////////////////
// iv) Print parent of a given element
void printParent(struct Node *root, int val) {
    if (root == NULL) return;
    if ((root->left && root->left->data == val) ||
        (root->right && root->right->data == val)) {
        printf("Parent of %d is %d\n", val, root->data);
        return;
    }
    if (root->left) printParent(root->left, val);
    if (root->right) printParent(root->right, val);
}

//////////////////////////////////////////////////////////
// v) Print the height (depth) of the tree
int height(struct Node *root) {
    if (root == NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

//////////////////////////////////////////////////////////
// vi) Print ancestors of a given element
int printAncestors(struct Node *root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

//////////////////////////////////////////////////////////
// vii) Count number of leaf nodes
int countLeafNodes(struct Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

//////////////////////////////////////////////////////////
// Main Function
int main() {
    struct Node *root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    int val;
    printf("\n\nEnter element to find its parent: ");
    scanf("%d", &val);
    printParent(root, val);

    printf("\nHeight (Depth) of the Tree: %d", height(root));

    printf("\n\nEnter element to print its ancestors: ");
    scanf("%d", &val);
    printf("Ancestors of %d: ", val);
    if (!printAncestors(root, val)) printf("No such element!");

    printf("\n\nNumber of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
