#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Create a doubly linked list
struct Node* create_list() {
    struct Node *newNode, *temp, *head = NULL;
    int choice, val;

    do {
        printf("Enter element: ");
        scanf("%d", &val);
        newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }

        printf("Enter 1 to continue | 0 to exit: ");
        scanf("%d", &choice);
    } while (choice == 1);

    return head;
}

// Display the DLL
void display(struct Node *temp) {
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search if value exists in list
int search(struct Node* head, int val) {
    while (head != NULL) {
        if (head->data == val)
            return 1;
        head = head->next;
    }
    return 0;
}

// Insert at end (unique values only)
void insert_end(struct Node** head, int val) {
    if (*head == NULL) {
        *head = createNode(val);
        return;
    }

    // check duplicate
    if (search(*head, val)) return;

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    struct Node* newNode = createNode(val);
    temp->next = newNode;
    newNode->prev = temp;
}

// Union
struct Node* U(struct Node* head1, struct Node* head2) {
    struct Node* head3 = NULL;

    // Copy all from head1
    while (head1 != NULL) {
        insert_end(&head3, head1->data);
        head1 = head1->next;
    }

    // Copy from head2 if not already present
    while (head2 != NULL) {
        insert_end(&head3, head2->data);
        head2 = head2->next;
    }

    return head3;
}

// Intersection
struct Node* intersection(struct Node* head1, struct Node* head2) {
    struct Node* head3 = NULL;

    while (head1 != NULL) {
        if (search(head2, head1->data))
            insert_end(&head3, head1->data);
        head1 = head1->next;
    }

    return head3;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL, *u = NULL, *inter = NULL;

    printf("Enter list 1 elements:\n");
    head1 = create_list();
    printf("Enter list 2 elements:\n");
    head2 = create_list();

    printf("\nX1: ");
    display(head1);
    printf("X2: ");
    display(head2);

    u = U(head1, head2);
    printf("\nUnion of the two lists:\n");
    display(u);

    inter = intersection(head1, head2);
    printf("\nIntersection of the two lists:\n");
    display(inter);

    return 0;
}
