#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* unique(int a[], int size, int* resultSize) {
    int* unique_elements = (int*)malloc(size * sizeof(int));
    int unique_count = 0;
    
    for (int i = 0; i < size; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < unique_count; j++) {
            if (a[i] == unique_elements[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unique_elements[unique_count] = a[i];
            unique_count++;
        }
    }
    
    *resultSize = unique_count;
    return unique_elements;
}

int main() {
    int size;
    printf("Enter size of the array : ");
    scanf("%d", &size);

    int array[size];
    int lower,higher;
    printf("Enter lower range : ");
    scanf("%d",&lower);
    printf("Enter higher range : ");
    scanf("%d",&higher);
    printf("Elements of array : ");
    srand(time(0));
    for(int i=1;i<=size;i++)
    {
        array[i] = (rand() % (higher-lower + 1)) + lower;
        printf("%d ",array[i]);
    }
    printf("\n");
    int result_size1;
    int* unique_result1 = unique(array, size, &result_size1);
    printf("Input size: %d, Basic operations: %d\n", size, size + result_size1);
    return 0;
}