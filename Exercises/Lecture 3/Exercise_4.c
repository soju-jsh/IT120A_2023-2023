/*
    Lecture 3
    Exercise: Comparing the characters between two strings
*/

#include <stdio.h>

int main() {
    // Variables
    char string1[100];
    char string2[100];

    int length1;
    int length2;

    // Input
    printf("String 1: ");
    gets(string1);
    printf("String 2: ");
    gets(string2);

    // Get length of each
    for (length1 = 0; string1[length1] != '\0'; length1++);
    for (length2 = 0; string2[length2] != '\0'; length2++);

    // Comparing the characters between two strings
    int isEqual = 1;

    if (length1 != length2) { // If the lengths are not equal, dli guro sila parehas noh?
        isEqual = 0;
    } else {
        for (int i = 0; i < length1; i++) { // Iterate over the characters

            // Compare the characters of each string at the current index
            if (string1[i] != string2[i]) { 
                // If naay galahi na character, dli ata sila parehas na string noh?
                isEqual = 0;
                // Exit loop, unnecessary to continue the loop and check other characters
                break; 
            }
        }
    }

    // Output
    if (isEqual) {
        printf("\nSame strings");
    } else {
        printf("\nDifferent strings");
    }

    return 0;
}