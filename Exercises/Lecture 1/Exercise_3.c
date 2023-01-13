/*
    Lecture 1
    Exercise: Calculates the area of a circle.
*/

#include <stdio.h>

int main() {
    // Declaration
    float radius;

    // Input
    printf("Radius = ");
    scanf("%f", &radius);

    // Calculation
    const float pi = 3.1416;
    float area = pi * (radius * radius);

    // Output
    printf("\npi * %.2f^2 = %.2f", radius, area);

    return 0;
}