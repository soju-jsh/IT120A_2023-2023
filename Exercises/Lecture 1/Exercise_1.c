/*
    Lecture 1
    Exercise: Given integers A and B, performs all four arithmetic operations.
*/

#include <stdio.h>

int main() {
    // Declaring our variables
    float var_A, var_B; 
    // yes u can use int, but ur input and output will be limited to integers (no decimal)

    // Input
    printf("A = ");
    scanf("%f", &var_A); // Gets user input and stores it inside var_A 
    printf("B = ");
    scanf("%f", &var_B); // Gets user input and stores it inside var_B

    // Output
    printf("\n%.2f + %.2f = %.2f\n", var_A, var_B, var_A + var_B);
    printf("%.2f - %.2f = %.2f\n", var_A, var_B, var_A - var_B);
    printf("%.2f * %.2f = %.2f\n", var_A, var_B, var_A * var_B);
    printf("%.2f / %.2f = %.2f\n", var_A, var_B, var_A / var_B);

    /*
        Another way:
            float sum = var_A + var_B;
            printf("\n%.2f + %.2f = %.2f\n", var_A, var_B, sum);

            float difference = var_A - var_B;
            printf("%.2f - %.2f = %.2f\n", var_A, var_B, difference);

            float product = var_A * var_B;
            printf("%.2f * %.2f = %.2f\n", var_A, var_B, product);

            float quotient = var_A / var_B;
            printf("%.2f / %.2f = %.2f\n", var_A, var_B, quotient);    
    */

    return 0;
}
