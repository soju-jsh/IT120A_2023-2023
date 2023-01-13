/*
    Lecture 3
    Exercise: Input string and character, find character in the string
*/

#include <stdio.h>

int main() {
    char string[100];
    char find_me;


    // Input
    printf("String: ");
    gets(string);
    printf("Find char: ");
    scanf(" %c", &find_me);

    // Finding the character
    for (int i = 0; string[i] != '\0'; i++) { // Iterate over the characters of string
        if (string[i] == find_me) {
            // Output
            printf("Found '%c' at index %i", find_me, i);
            return 0;
        }
    }
    
    // Output
    printf("Can't find the character '%c'", find_me);

    return 0;
}