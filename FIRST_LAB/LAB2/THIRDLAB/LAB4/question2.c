#include <stdio.h>

int linear_search_first_occurrence(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int element_to_search;
    printf("Enter element to be searched: ");
    scanf("%d", &element_to_search);

    // Using the linear search function
    int position = linear_search_first_occurrence(arr, size, element_to_search);

    if (position != -1) {
        printf("%d found at position %d.\n", element_to_search, position + 1);
    } else {
        printf("%d not found.\n", element_to_search);
    }

    return 0;
}
