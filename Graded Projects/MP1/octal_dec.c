/*  

    Octal/Decimal Number System
    Assigned to 11 - Upsilon

    Basic Version
        :: Does not include anti-idiot system

*/

#include <stdio.h>

// Functions
int len(char string[]);

// Main Function
int main() {
    // Input
    char input[32];
    printf("> ");
    gets(input);

    // Get input string length
    int length = len(input);

    int decimal = 0;
    int octal = 0;

    // Identify suffix
    switch (input[length - 1]) { // input[length - 1] is the last character of the string
        case 'd':
            for (int i = 0; i < length - 1; i++) { // Convert string to integer
                decimal *= 10;
                decimal += input[i] - '0';
            }
            for (int place = 1; decimal > 0; place *= 10) { // Decimal to Octal
                octal += decimal % 8 * place;
                decimal /= 8;
            }
            printf("%io", octal); // Output
            break;

        case 'o':
            for (int i = 0; i < length - 1; i++) { // Octal to Decimal
                decimal *= 8;
                decimal += input[i] - '0';
            }
            printf("%id", decimal); // Output
            break;

        default: // Evaluated if suffix is not 'd' or 'o'
            printf("Invalid Suffix");
            break;
    }

    return 0;
}

// Definition of functions
int len(char string[]) {
    int length;
    for (length = 0; string[length] != '\0'; length++);
    return length;
}