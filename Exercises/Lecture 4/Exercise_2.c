/*
    Lecture 4
    Exercise: Palindrome detector
*/

#include <stdio.h>

int main() {
    char string[100];

    // Input
    printf("String: ");
    gets(string);

    // Get length
    int length;
    for (length = 0; string[length] != '\0'; length++);

    // Copy string but in reverse to reversed variable
    char reversed[100] = "";
    for (int i = 0, y = length - 1; i < length; i++) {
        reversed[i] = string[y--];
    }

    // Compare the two strings if it's the same
    // By comparing the characters of each string
    for (int i = 0; i < length; i++) {
        if (string[i] != reversed[i]) {
            printf("Not a palidrome");
            return 0;
        }
    }
    printf("Palindrome detected");
    return 0;
}