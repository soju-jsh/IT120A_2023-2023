/*
    Lecture 1
    Exercise: Converts time in days to years, weeks, and days.
*/

#include <stdio.h>

int main() {
    // Declaration
    int days;

    // Input
    printf("Input in days: ");
    scanf("%i", &days);

    // Calculations
    int weeks, years;
    years = days / 365;
    days = days % 365;
    weeks = days / 7;
    days = days % 7;

    // Output
    printf("\n%i Years\n", years);
    printf("%i Weeks\n", weeks);
    printf("%i Days\n", days);

    return 0;
}