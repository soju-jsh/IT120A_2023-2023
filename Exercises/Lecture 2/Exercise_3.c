/*
    Lecture 2
    Exercise: Computes the summation of counting numbers from 1 to N.
*/

#include <stdio.h>

int main() {
    // Declaration
    int var_N;

    // Input
    printf("N: ");
    scanf("%i", &var_N);

    // Consideration(s)
    if (var_N < 0) {
        printf("Positive integers only");
        return 0;
    }

    // Calculations
    int sum = 0;
    for (int i = 0; i <= var_N; i++) {
        sum += i;
    }

    // Output
    printf("Sum: %i", sum);

    return 0;
}