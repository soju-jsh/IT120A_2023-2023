/*
    Lecture 2
    Exercise: 
        Upgrades the simple calculator program so that the user can 
        continuously use the program until they type ‘X’ to exit.
*/

#include <stdio.h>

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

        printf("Operation [+, -, *, /]");
        scanf(" %c", &operation);
        
        float sum, difference, product, quotient;

        switch (operation) {
            case '+':
                sum = var_A + var_B;
                printf("\n%.2f + %.2f = %.2f\n", var_A, var_B, sum);            
                break;

            case '-':
                difference = var_A - var_B;
                printf("\n%.2f - %.2f = %.2f\n", var_A, var_B, difference);
                break;

            case '*':
                product = var_A * var_B;
                printf("\n%.2f * %.2f = %.2f\n", var_A, var_B, product);            
                break;

            case '/':
                quotient = var_A / var_B;
                printf("\n%.2f / %.2f = %.2f\n", var_A, var_B, quotient);             
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