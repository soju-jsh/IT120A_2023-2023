/*
    Lecture 2
    Exercise: Performs multiplication via repeated addition.
*/

#include <stdio.h>

int main() {
    // Declaration
    int var_A, var_B;

    // Input
    printf("A: ");
    scanf("%i", &var_A);
    printf("B: ");
    scanf("%i", &var_B);

    // Considerations
    if (var_A == 0 || var_B == 0) {
        printf("\nAnswer: %i", 0);
        return 0;
    } else if (var_A < 0 || var_B < 0) {
        printf("\nPositive integers only");
        return 0;
    }

    // Calculation
    int sum = var_A;
    for (int i = 1; i < var_B; i++) {
        sum += var_A;
    }

    // Output
    printf("\nAnswer: %i", sum);

    return 0;
}