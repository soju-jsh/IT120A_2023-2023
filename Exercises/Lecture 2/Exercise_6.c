/*
    Lecture 2
    Exercise: Prints the Fibonacci series up to the Nth term.
*/

#include <stdio.h>

int main() {
    int var_A = 0, var_B = 1;
    int var_C;
    int var_N;

    // Input
    printf("N: ");
    scanf("%i", &var_N);

    // Consideration(s)
    if (var_N < 0) {
        printf("Positive integers only");
        return 0;
    } if (var_N == 0) {
        printf("Sequence: 0");
        return 0;
    }

    // Starting Output
    printf("Sequence: %i, %i, ", var_A, var_B);

    // Calculation(s) + Output
    for (int i = 1; i < var_N; i++) {
        var_C = var_A + var_B;

        // Output
        printf("%i, ", var_C);

        var_A = var_B;
        var_B = var_C;
    }

    return 0;
}