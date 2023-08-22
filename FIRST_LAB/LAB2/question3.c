#include <stdio.h>

// Function to calculate the kth Fibonacci number
unsigned long long fibonacci(int k) {
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;

    unsigned long long prev = 0;
    unsigned long long current = 1;
    unsigned long long next;

    for (int i = 2; i <= k; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

// Function to calculate the GCD using Euclid's algorithm
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int k;
    printf("Input: Enter k - ");
    scanf("%d", &k);

    // Print the GCD, nloop, and nloop/k for each pair of kth and k+1th Fibonacci numbers
    for (int i = 2; i <= k; i++) {
        unsigned long long fib1 = fibonacci(i);
        unsigned long long fib2 = fibonacci(i + 1);
        
        // Calculate the GCD
        unsigned long long result = gcd(fib1, fib2);

        // Calculate the number of times the GCD loop executes (nloop)
        unsigned long long nloop = 0;
        unsigned long long a = fib1;
        unsigned long long b = fib2;
        while (b != 0) {
            unsigned long long temp = b;
            b = a % b;
            a = temp;
            nloop++;
        }

        // Calculate the estimated parameter c1
        double c1 = (double)nloop / i;

        // Print the output for the current k and k+1 Fibonacci numbers
        printf("Output: %dth and %dth Fibonacci numbers - %llu, %llu\n", i, i + 1, fib1, fib2);
        printf("\tGCD = %llu\n", result);
        printf("\tnloop = %llu\n", nloop);
        printf("\tand Estimated parameter, c1 = %.15lf\n\n", c1);
    }

    return 0;
}