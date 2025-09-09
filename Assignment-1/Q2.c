#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    int new_size = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < new_size; j++) {
            if (arr[i] == arr[j]) { 
                found = 1; 
                break;
            }
        }
        if (!found) {
            arr[new_size] = arr[i];
            new_size++;
        }
    }
    return new_size;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf(" \n");

    int new_size = removeDuplicates(arr, n);

    printf("Array after removing duplicates: \n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
