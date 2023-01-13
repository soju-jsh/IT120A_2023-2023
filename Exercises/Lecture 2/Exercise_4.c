/*
    Lecture 2
    Exercise: Computes the factorial of N.
*/

#include <stdio.h>

int main() {
    int var_N;

    // Input
    printf("N: ");
    scanf("%i", &var_N);

    // Consideration(s)
    if (var_N > 12) {
        printf("Only up to 12"); 
        // Reason: Factorial of 13 and above is too large for integer type variable
        return 0;
    } else if (var_N < 0) {
        printf("Positive integers only");
        return 0;
    }

    // Calculations
    int factorial = 1;
    for (int i = 1; i <= var_N; i++) {
        factorial *= i;
    }

    // Output
    printf("Factorial: %i", factorial);

    return 0;
}