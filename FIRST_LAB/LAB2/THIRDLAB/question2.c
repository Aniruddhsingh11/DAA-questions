#include <stdio.h>

int main()
{
    int target, guess, low, high;

    printf("Enter the number (less than 1000000) : ");
    scanf("%d", &target);

    low = 1;
    high = 1000000;

    while (1)
    {

        guess = (low + high) / 2;
        printf("A's guessed : %d", guess);

        if (guess == target)
        {
            printf("\nB's response : You have guessed correct\n");
            break;
        }
        else if (guess < target)
        {
            printf("\nB's response : A little high\n");
            low = guess + 1;
        }
        else
        {
            printf("\nB's response : A little low\n");
            high = guess - 1;
        }
    }
    printf("\n");
    return 0;
}