#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,j,i,temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }

    printf("Soreted array is : ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}