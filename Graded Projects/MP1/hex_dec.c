/*  

    Hex/Decimal Number System
    Assigned to 11 - Pi

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
    char hex_equivalent[12] = "";

    // Identify suffix
    switch (input[length - 1]) { // input[length - 1] is the last character of the string
        case 'd':
            for (int i = 0; i < length - 1; i++) { // Convert string to integer
                decimal *= 10;
                decimal += input[i] - '0';
            }
            for (int i = 0; decimal > 0; i++) { // Decimal to Hex
                if (decimal % 16 >= 0 && decimal % 16 <= 9) {
                    hex_equivalent[i] = decimal % 16 + '0';
                } else {
                    hex_equivalent[i] = decimal % 16 + 55;
                }
                decimal /= 16;
            }
            for (int i = 0; i < len(hex_equivalent) / 2; i++) { // Reverse String
                char TMP = hex_equivalent[i];
                hex_equivalent[i] = hex_equivalent[len(hex_equivalent) - 1 - i];
                hex_equivalent[len(hex_equivalent) - 1 - i] = TMP;
            }

            printf("%sh", hex_equivalent); // Output
            break;

        case 'h':
            for (int i = 0; i < length - 1; i++) { // Hexa to Decimal
                decimal *= 16;
                if (input[i] >= '0' && input[i] <= '9') {
                    decimal += input[i] - '0';
                } else {
                    decimal += input[i] - 55;
                }
            }
            printf("%id", decimal); // Output
            break;

        default: // Evaluated if suffix is not 'd' or 'h'
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