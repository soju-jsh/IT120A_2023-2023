/*
    Lecture 1
    Exercise: Given 10 grades, calculates the average and percentage.

    Note: 
        This is a slightly advanced version for this exercise
        Feel free to PM me for the beginner friendly version ^^
        
        Discord: Soju#4662
*/

#include <stdio.h>

int main() {
    // Declaration
    float grades[10];
    float total = 0;

    // Input
    printf("Input 10 grades:\n");
    for (int i = 0; i < 10; i++) {
        printf("> ");
        scanf("%f", &grades[i]);
        total += grades[i];
    }

    // Output
    float average = total / 10;
    printf("\nAverage: %.2f\n", average);

    printf("Percentage:\n");
    for (int i = 0; i < 10; i++) {
        printf("> %.2f - %.2f%\n", grades[i], grades[i] / total * 100);
    }


    return 0;
}