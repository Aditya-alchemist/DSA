#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node with data %d added to the list.\n", data);
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = *head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found in the list.\n", data);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current); 
    printf("Node with data %d deleted from the list.\n", data);
}

int main() {
    int n, choice, data;
    struct Node* head = NULL;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    head = createList(n);
    displayList(head);    

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;

            case 2:
                printf("Enter data of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}