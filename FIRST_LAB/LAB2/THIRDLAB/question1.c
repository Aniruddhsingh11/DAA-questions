#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int counter = 0;

int recursiveMin(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        counter++;
        int min = recursiveMin(a, n - 1);
        if (a[n - 1] < min)
        {
            return a[n - 1];
        }
        else
        {
            return min;
        }
    }
}
int main()
{
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

    printf("Smallest number is : %d\n", recursiveMin(array, size));

    printf("Depth of the recursion is : %d\n", counter);

    return 0;
}