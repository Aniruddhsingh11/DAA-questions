#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double fabs(double x) {
    return (x < 0) ? -x : x;
}

double logCustom(double x) {
    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double termSquared = term * term;
    int n = 1;

    while (1) {
        result += term / n;
        term *= termSquared;
        n += 2;
        if (fabs(term / n) < 1e-15) {
            break;
        }
    }

    return 2 * result;
}

double sine(double x, int d, int* loopCount, double* loopRatio) {
    double result = 0.0;
    int sign = 1;
    *loopCount = 0;

    x = x * 3.14 / 180.0;

    for (int n = 1;; n += 2) {
        double term = sign * power(x, n) / factorial(n);
        result += term;
        (*loopCount)++;

        if (fabs(term) < pow(10, -d)) {
            break;
        }

        sign *= -1;
    }

    *loopRatio = log(*loopCount) / d;
    return result;
}

int main() {
    double x;
    int d;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter the number of decimal places: ");
    scanf("%d", &d);

    int loopCount;
    double loopRatio;
    double result = sine(x, d, &loopCount, &loopRatio);
    printf("%.15lf\n", result);

    printf("Number of times loop is executed : %d\n", loopCount);
    printf("C1 : %.15lf\n", loopRatio);

    return 0;
}