/*
    Lecture 1
    Exercise: Converts measurements in centimeters to inches.
*/

#include <stdio.h>

int main() {
    // Declaration
    float centimeters;

    // Input
    printf("Centimeters: ");
    scanf("%f", &centimeters);

    // Calculation
    float inches = centimeters * 0.393701; // 1in = 0.393701cm

    // Output
    printf("Inches(s): %.2f", inches);

    return 0;
}