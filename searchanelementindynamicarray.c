#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, element, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find: ");
    scanf("%d", &element);

    
    int found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == element) { 
            printf("Element %d found at index %d\n", element, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", element);
    }

    
    free(arr);
    return 0;
}
