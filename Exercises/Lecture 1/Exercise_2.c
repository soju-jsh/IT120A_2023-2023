/*
    Lecture 1
    Exercise: Given integers L and W, calculates the area of a rectangle.
*/

#include <stdio.h>

int main() {
    // Declaring our variables
    float length, width;
    // yes u can use int, but ur input and output will be limited to integers (no decimal)

    // Input
    printf("Length = ");
    scanf("%f", &length); // Gets user input and stores it inside length 
    printf("Width = ");
    scanf("%f", &width); // Gets user input and stores it inside width

    // Output
    float area = length * width; // Area = LW
    printf("\n%.2f * %.2f = %.2f", length, width, area);

    return 0;
}