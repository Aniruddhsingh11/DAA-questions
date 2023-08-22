#include <stdio.h>
void calculateProduct(int arr[], int n)
{
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = product / arr[i];
    }
}
int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    if (n <= 1)
    {
        printf("Array size greater than 1.\n");
        return 1;
    }
    int arr[n];
    printf("Enter the elements  array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    calculateProduct(arr, n);
    printf("Output Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}