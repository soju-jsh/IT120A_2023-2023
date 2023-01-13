/*
    Lecture 4
    Exercise: 
        Rewrite simple calculator but with each operations having their own functions
*/

#include <stdio.h>

// Functions
float add(float var_A, float var_B);
float subtract(float var_A, float var_B);
float divide(float var_A, float var_B);
float multiply(float var_A, float var_B);

int main() {
    // Declaring our variables
    float var_A, var_B; 

    char operation;
    char again;

    do {
        // Input
        printf("A: ");
        scanf("%f", &var_A);

        printf("B: ");
        scanf("%f", &var_B);

        printf("Operation [+, -, *, /]: ");
        scanf(" %c", &operation);

        switch (operation) {
            case '+':
                printf("\n%.2f + %.2f = %.2f\n", var_A, var_B, add(var_A, var_B));            
                break;

            case '-':
                printf("\n%.2f - %.2f = %.2f\n", var_A, var_B, subtract(var_A, var_B));
                break;

            case '*':
                printf("\n%.2f * %.2f = %.2f\n", var_A, var_B, multiply(var_A, var_B));            
                break;

            case '/':
                printf("\n%.2f / %.2f = %.2f\n", var_A, var_B, divide(var_A, var_B));             
                break;
            
            default:
                printf("\nInvalid Operator\n");
                break;
        }

        // Type 'x' to exit
        printf("\nDo you want to calculate again? y or n: ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y'); // The loops if user inputs 'y' or 'Y'

    return 0;
}


float add(float var_A, float var_B) {
    return var_A + var_B;
}

float subtract(float var_A, float var_B) {
    return var_A - var_B;
}

float divide(float var_A, float var_B) {
    return var_A / var_B;
}

float multiply(float var_A, float var_B) {
    return var_A * var_B;
}