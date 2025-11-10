//multiply using circular linked list

#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff, pow;
    struct PolyNode *prev, *next;
};

// Create header node
struct PolyNode* createHeader() {
    struct PolyNode* head = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    head->coeff = 0;
    head->pow = -1;  // header dummy value
    head->next = head->prev = head;
    return head;
}

// Insert in descending order, combine like terms
void insertTerm(struct PolyNode* head, int coeff, int pow) {
    if (coeff == 0) return;

    struct PolyNode* temp = head->next;

    // Traverse until suitable position
    while (temp != head && temp->pow > pow)
        temp = temp->next;

    if (temp != head && temp->pow == pow) {
        // Merge coefficient
        temp->coeff += coeff;
        if (temp->coeff == 0) { // remove if coeff becomes 0
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        return;
    }

    // Create new node
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->pow = pow;

    // Insert before temp
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Display polynomial
void display(struct PolyNode* head) {
    struct PolyNode* temp = head->next;
    if (temp == head) {
        printf("0\n");
        return;
    }
    while (temp != head) {
        printf("%d", temp->coeff);
        if (temp->pow != 0)
            printf("x^%d", temp->pow);
        if (temp->next != head && temp->next->coeff >= 0)
            printf(" + ");
        else if (temp->next != head)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// Multiply two polynomials
struct PolyNode* multiply(struct PolyNode* head1, struct PolyNode* head2) {
    struct PolyNode* result = createHeader();

    struct PolyNode* t1 = head1->next;
    while (t1 != head1) {
        struct PolyNode* t2 = head2->next;
        while (t2 != head2) {
            int coeff = t1->coeff * t2->coeff;
            int pow = t1->pow + t2->pow;
            insertTerm(result, coeff, pow);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return result;
}

int main() {
    struct PolyNode* poly1 = createHeader();
    struct PolyNode* poly2 = createHeader();
    struct PolyNode* product;

    int n, coeff, pow;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter coeff and power (in descending order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        insertTerm(poly1, coeff, pow);
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter coeff and power (in descending order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        insertTerm(poly2, coeff, pow);
    }

    // Display inputs
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    // Multiply
    product = multiply(poly1, poly2);

    printf("Product: ");
    display(product);

    return 0;
}
