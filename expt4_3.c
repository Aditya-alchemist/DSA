#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displaySparseMatrix(struct Node* head) {
    if (head == NULL) {
        printf("The sparse matrix is empty.\n");
        return;
    }

    printf("Sparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int m, n, i, j, value;
    struct Node* sparseMatrix = NULL;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element at (%d, %d): ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                insert(&sparseMatrix, i, j, value);
            }
        }
    }

    displaySparseMatrix(sparseMatrix);

    return 0;
}
