#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void findSecondSmallestLargest(int arr[], int n)
{
    if (n < 2)
    {
        printf("Array size should be at least 2 to find second smallest and second largest.\n");
        return;
    }

    int smallest = arr[0];
    int second_smallest = arr[0];
    int largest = arr[0];
    int second_largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }

        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }

    printf("Second Smallest Element: %d\n", second_smallest);
    printf("Second Largest Element: %d\n", second_largest);
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Array size should be greater than zero.\n");
        return 1;
    }

    // Set the seed for random number generation
    srand(time(0));

    int arr[n];
    int lower_range, upper_range;

    printf("Enter the lower range for random number generation: ");
    scanf("%d", &lower_range);

    printf("Enter the upper range for random number generation: ");
    scanf("%d", &upper_range);

    if (lower_range > upper_range)
    {
        printf("Invalid range. Lower range should be less than or equal to the upper range.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (upper_range - lower_range + 1) + lower_range;
    }

    printf("Generated Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    findSecondSmallestLargest(arr, n);

    return 0;
}
