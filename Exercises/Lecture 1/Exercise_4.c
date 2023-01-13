/*
    Lecture 1
    Exercise: Calculates the volume of a cylinder.
*/

#include <stdio.h>

int main() {
    // Declaration
    float radius, height;

    // Input
    printf("Radius = ");
    scanf("%f", &radius);
    printf("Height = ");
    scanf("%f", &height);

    // Calculation
    const float pi = 3.1416;
    float volume = pi * (radius * radius) * height;

    // Output
    printf("\npi * %.2f^2 * %.2f = %.2f", radius, height, volume);

    return 0;
}