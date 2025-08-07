#include <stdio.h>
#include <stdlib.h>

int arr[70];
int size = 0;
void create() {
    printf("Enter the number of elements (max 70): ");
    scanf("%d", &size);
    if (size > 70 || size < 0) {
        printf("Invalid size.\n");
        size = 0;
        return;
    }
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

void display() {
    if (size == 0) {
        printf("Array is empty. Please create an array first.\n");
        return;
    }
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    if (size >= 70) {
        printf("Array is full. Can’t insert more elements.\n");
        return;
    }
    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (0 to %d) to insert element: ", size);
    scanf("%d", &position);
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    size++;
    printf("Element inserted successfully.\n");
}

void delete_element() {
    if (size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    int position;
    printf("Enter the position (0 to %d) of the element to delete: ", size - 1);
    scanf("%d", &position);
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return;
    }
    printf("Deleted element: %d\n", arr[position]);
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully.\n");
}

void linearSearch() {
    if (size == 0) {
        printf("Array is empty. Cannot perform search.\n");
        return;
    }
    int element, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d\n", element, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }
}

int main() {
    int choice;
    do {
        printf("\n----- MENU -----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Linear Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete_element();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}