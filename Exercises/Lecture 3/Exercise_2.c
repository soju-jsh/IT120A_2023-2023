/*
    Lecture 3
    Exercise: Reverse string array
*/

#include <stdio.h>

int main() {
    char string[100];

    // Input
    printf("> ");
    gets(string);

    // Get string length
    int length;
    for (length = 0; string[length] != '\0'; length++);

    // Reverse string
    for (int i = 0; i < length / 2; i++) {
        char TMP = string[length - 1 - i];
        string[length - 1 - i] = string[i];
        string[i] = TMP;
    }

    // Output
    printf("%s", string);

    return 0;
}