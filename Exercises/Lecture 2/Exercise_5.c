/*
    Lecture 2
    Exercise: Computes the sum of even or odd numbers up to N.
*/

#include <stdio.h>

int main() {
    int var_N;
    int choice;

    // Input
    printf("N: ");
    scanf("%i", &var_N);
    printf("1-Odd or 2-Even: ");
    scanf("%i", &choice);

    // Consideration(s)
    if (var_N < 0) {
        printf("Positive integers only");
        return 0;
    }

    // Calculation
    int sum = 0;
    switch (choice) {
        case 1:
            for (int i = 1; i <= var_N; i += 2) {
                sum += i;
                printf("%i ", i);
            }
            break;

        case 2:
            for (int i = 2; i <= var_N; i += 2) {
                sum += i;
                printf("%i ", i);
            }
            break;
        
        default:
            printf("\nErrawr");
            return 0;
            break;
    }

    // Output
    printf("\nSum: %i", sum);

    return 0;
}