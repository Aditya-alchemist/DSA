#include <stdio.h>

void find_elements_between(int arr[], int n, int a, int b) {
    int lower = (a < b) ? a : b;
    int upper = (a > b) ? a : b;

    int count = 0;
    printf("Elements between %d and %d (inclusive): ", a, b);

    for (int i = 0; i < n; i++) {
        if (arr[i] >= lower && arr[i] <= upper) {
            printf("%d ", arr[i]);
            count++;
        }
    }

    printf("\nCount: %d\n", count);
}

int main() {
    int arr[] = {1, 2, 2, 7, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a = 2, b = 5;

    find_elements_between(arr, n, a, b);

    return 0;
}
