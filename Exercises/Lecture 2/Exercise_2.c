/*
    Lecture 2
    Exercise: Performs division via repeated subtraction.
*/

#include <stdio.h>

int main() {
    // Declarations
    int var_A, var_B;

    // Input
    printf("A: ");
    scanf("%i", &var_A);
    printf("B: ");
    scanf("%i", &var_B);

    // Considerations
    if (var_A == 0) {
        printf("\nAnswer: %i", 0);
        return 0;
    } else if (var_B == 0) {
        printf("\nAnswer: Undefined");
        return 0;
    } else if (var_A < 0 || var_B < 0) {
        printf("\nPositive integers only");
        return 0;
    } else if (var_A < var_B) {
        printf("\nA must be greater or equal to B");
        return 0;
    }

    // Calculations
    int leftover = var_A;
    int quotient;
    for (quotient = 0; leftover >=  var_B; quotient++) {
        leftover -= var_B;
    }

    // Output
    printf("\nQuotient: %i\n", quotient);
    printf("Remainder: %i\n", leftover);

    return 0;
}