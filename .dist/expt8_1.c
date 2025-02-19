#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

struct Node* createRollNumberList(long rollNumber) {
    struct Node* head = NULL;
    char rollStr[20];
    sprintf(rollStr, "%ld", rollNumber);
    for (int i = 0; i < strlen(rollStr); i++) {
        append(&head, rollStr[i] - '0');
    }
    return head;
}

struct Node* reverseKGroup(struct Node* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    struct Node dummy;
    dummy.next = head;
    struct Node* prevGroupEnd = &dummy;
    struct Node* current = head;

    while (count >= k) {
        struct Node* groupStart = current;
        struct Node* prev = NULL;

        for (int i = 0; i < k; i++) {
            struct Node* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        prevGroupEnd->next = prev;
        groupStart->next = current;
        prevGroupEnd = groupStart;
        count -= k;
    }

    return dummy.next;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    long rollNumber = 2304160;
    int k;

    printf("Roll Number: %ld\n", rollNumber);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    struct Node* head = createRollNumberList(rollNumber);

    printf("Original Linked List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("After reversing in groups of %d: ", k);
    printList(head);

    freeList(head);

    return 0;
}
