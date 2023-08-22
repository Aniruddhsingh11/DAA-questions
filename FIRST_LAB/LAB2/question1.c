#include <stdio.h>
#include <stdlib.h>

int loop1 = 0;
int loop2 = 0;

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        loop1++;
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* generatePrimes(int n, int* numPrimes) {
    int* primes = (int*)malloc(sizeof(int) * n);
    int j = 0;
    for (int t = 2; t <= n; t++) {
        loop2++;
        if (isPrime(t) == 1) {
            primes[j++] = t;
        }
    }
    *numPrimes = j;
    return primes;
}

int main() {
    int x;
    printf("Enter value of x: ");
    scanf("%d", &x);

    int numPrimes;
    int* primes = generatePrimes(x, &numPrimes);

    // printf("Prime numbers: ");
    // for (int i = 0; i < numPrimes; i++) {
    //     printf("%d ", primes[i]);
    // }
    printf("Outer loop: %d\n", loop1);
    printf("Inner loop: %d\n", loop2);

    double c1 = (double)loop1 / x; // Cast loop1 to double before division
    double c2 = (double)loop2 / x; // Cast loop2 to double before division

    printf("C1: %.2f\n", c1);
    printf("C2: %.2f\n", c2);

    free(primes);
    return 0;
}