/*
    Lecture 2
    Exercise: 
        Prints a right triangle of asterisks with the hypotenuse ascending from left to right.
*/

#include <stdio.h>

int main() {

    // Width and Length = 10

    for (int y = 1; y <= 10; y++) {
        for (int x = 0; x < 10 - y; x++) {
            printf("   ");
        }
        for (int x = 10 - y; x < 10; x++) {
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}