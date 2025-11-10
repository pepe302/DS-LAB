//add two polynomials using a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff, expo;
    struct Node *prev, *next;
};


struct Node* createNode(int coeff, int expo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insert_end(struct Node** head, int coeff, int expo) {
    struct Node* newNode = createNode(coeff, expo);

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display polynomial
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->coeff);
        if (head->expo != 0)
            printf("x^%d", head->expo);
        if (head->next != NULL && head->next->coeff >= 0)
            printf(" + ");
        else if (head->next != NULL)
            printf(" ");
        head = head->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* add(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->expo == head2->expo) {
            int sumCoeff = head1->coeff + head2->coeff;
            if (sumCoeff != 0) // only add if non-zero
                insert_end(&result, sumCoeff, head1->expo);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->expo > head2->expo) {
            insert_end(&result, head1->coeff, head1->expo);
            head1 = head1->next;
        }
        else {
            insert_end(&result, head2->coeff, head2->expo);
            head2 = head2->next;
        }
    }

    // Add remaining terms
    while (head1 != NULL) {
        insert_end(&result, head1->coeff, head1->expo);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        insert_end(&result, head2->coeff, head2->expo);
        head2 = head2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    int n, coeff, expo;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter coeff and expoer (in descending order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &expo);
        insert_end(&poly1, coeff, expo);
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter coeff and expoer (in descending order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &expo);
        insert_end(&poly2, coeff, expo);
    }

    // Display inputs
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    // Add
    sum = add(poly1, poly2);

    printf("Sum: ");
    display(sum);

    return 0;
}
