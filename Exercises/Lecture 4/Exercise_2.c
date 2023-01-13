/*
    Lecture 4
    Exercise: 
        Palindrome detector
        Create separate functions for determining the length of a string and reversing a string.
*/

#include <stdio.h>

// Function
int len(char string[]) {
    int length;
    for (length = 0; string[length] != '\0'; length++);
    return length;
}

int main() {
    char string[100];

    // Input
    printf("String: ");
    gets(string);

    // Get length
    int length = len(string);

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
