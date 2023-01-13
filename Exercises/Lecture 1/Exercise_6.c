/*
    Lecture 1
    Exercise: Converts measurements in feet to centimeters.
*/

#include <stdio.h>

int main() {
    // Declaration/s
    float feet;

    // Input
    printf("Input in feet or foot samok: ");
    scanf("%f", &feet);

    // Calculation
    float centimeters = feet * 30.48;

    // Output
    printf("Centimeters: %.2f", centimeters);

    return 0;
}