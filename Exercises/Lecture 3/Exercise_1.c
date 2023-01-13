/*
    Lecture 3
    Exercise: printf string in reverse
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

    // Output
    for (int i = length; i >= 0; i--) {
        printf("%c", string[i]);
    }

    return 0;
}