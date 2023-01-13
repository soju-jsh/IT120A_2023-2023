/*  

    Binary/Decimal Number System
    Assigned to 11 - Chi

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
    char binary_equivalent[32] = "";

    // Identify suffix
    switch (input[length - 1]) { // input[length - 1] is the last character of the string
        case 'd':
            for (int i = 0; i < length - 1; i++) { // Convert string to integer
                decimal *= 10;
                decimal += input[i] - '0';
            }
            for (int i = 0; decimal > 0; i++) { // Decimal to Binary
                binary_equivalent[i] = decimal % 2 + '0';
                decimal /= 2;
            }
            for (int i = 0; i < len(binary_equivalent) / 2; i++) { // Reverse String
                char TMP = binary_equivalent[i];
                binary_equivalent[i] = binary_equivalent[len(binary_equivalent) - 1 - i];
                binary_equivalent[len(binary_equivalent) - 1 - i] = TMP;
            }
            printf("%sb", binary_equivalent); // Output
            break;

        case 'b':
            for (int i = 0; i < length - 1; i++) { // Binary to Decimal
                decimal *= 2;
                decimal += input[i] - '0';
            }
            printf("%id", decimal); // Output
            break;

        default: // Evaluated if suffix is not 'd' or 'b'
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