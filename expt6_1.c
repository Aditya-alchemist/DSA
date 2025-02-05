#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");      
        
    }
    printf("%d popped from stack.\n", stack[top--]);
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Check if Stack is Empty\n");
        printf("2. Display Stack\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isEmpty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 4:
                pop();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
