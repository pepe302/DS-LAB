//addition of long integers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end (for building number left-to-right)
void insert_end(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

// Insert at front (for result digits)
void insert_front(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Display number
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Get tail of list
struct Node* get_tail(struct Node* head) {
    while (head && head->next != NULL)
        head = head->next;
    return head;
}

// Add two long integers
struct Node* add(struct Node* head1, struct Node* head2) {
    struct Node *tail1 = get_tail(head1);
    struct Node *tail2 = get_tail(head2);
    struct Node *result = NULL;

    int carry = 0;

    while (tail1 != NULL || tail2 != NULL) {
        int x = (tail1 ? tail1->data : 0);
        int y = (tail2 ? tail2->data : 0);

        int sum = x + y + carry;
        carry = sum / 10;

        insert_front(&result, sum % 10);

        if (tail1) tail1 = tail1->prev;
        if (tail2) tail2 = tail2->prev;
    }

    if (carry)
        insert_front(&result, carry);

    return result;
}

int main() {
    char num1[100], num2[100];
    struct Node *head1 = NULL, *head2 = NULL, *result = NULL;

    printf("Enter first long integer: ");
    scanf("%s", num1);
    printf("Enter second long integer: ");
    scanf("%s", num2);

    // Store digits in DLLs
    for (int i = 0; i < strlen(num1); i++)
        insert_end(&head1, num1[i] - '0');

    for (int i = 0; i < strlen(num2); i++)
        insert_end(&head2, num2[i] - '0');

    printf("Number 1: ");
    display(head1);
    printf("Number 2: ");
    display(head2);

    result = add(head1, head2);

    printf("Sum: ");
    display(result);

    return 0;
}
