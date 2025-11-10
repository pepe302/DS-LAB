//washing machine

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    int time; // booking time in minutes
    struct User *prev, *next;
};

struct User* head = NULL;

// Create a new user node
struct User* createUser(char name[], int time) {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    strcpy(newUser->name, name);
    newUser->time = time;
    newUser->next = newUser->prev = NULL;
    return newUser;
}

// Add user to circular doubly linked list
void addUser(char name[], int time) {
    struct User* newUser = createUser(name, time);
    if (head == NULL) {
        head = newUser;
        head->next = head->prev = head; // circular link
    } else {
        struct User* last = head->prev;
        last->next = newUser;
        newUser->prev = last;
        newUser->next = head;
        head->prev = newUser;
    }
    printf("User %s booked machine for %d minutes.\n", name, time);
}

// Remove a user when their time is up
void removeUser(struct User* user) {
    if (user->next == user && user->prev == user) {
        // Only one user in the list
        free(user);
        head = NULL;
        return;
    }

    struct User* prevNode = user->prev;
    struct User* nextNode = user->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    if (user == head) {
        head = nextNode;
    }

    printf("User %s's time is over, leaving queue.\n", user->name);
    free(user);
}

// Simulate the washing machine usage
void simulate() {
    if (head == NULL) {
        printf("No users in the queue.\n");
        return;
    }

    struct User* current = head;
    while (head != NULL) {
        printf("\nWashing machine in use by %s for %d minutes.\n", current->name, current->time);
        struct User* toRemove = current;
        current = current->next; // move to next before removal
        removeUser(toRemove);
    }

    printf("\nAll users have finished their turn.\n");
}

int main() {
    int n, time;
    char name[50];

    printf("Enter number of users booking the machine: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter user name: ");
        scanf("%s", name);
        printf("Enter booking time (in minutes): ");
        scanf("%d", &time);
        addUser(name, time);
    }

    printf("\n--- Simulation Start ---\n");
    simulate();
    printf("--- Simulation End ---\n");

    return 0;
}
