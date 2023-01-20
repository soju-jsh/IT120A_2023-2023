/*
    Function
        Purpose: Convert string to integer, if possible
        Return: (int) Converted integer
*/

#include <stdio.h>

int string_to_integer(char string[]) {
    int converted = 0;

    // Gets the string length
    int length;
    for(length = 0; string[length] != '\0'; length++);
    /*
        or you could use the function from the previous exercise
            int length = get_length(string);
    */

    /*
        or you could use the function from the previous exercise
            for (int i = 0; i < get_length(string); i++)
    */
    for (int i = 0; i < length - 1; i++) {
        // If the current character is not in the range of '0' and '9', throw an error
        if(!(string[i] >= '0' && string[i] <= '9')) {
            printf("Conversion not possible\n");
            return -1;
        }
        converted *= 10;
        converted += string[i] - '0';
    }

    return converted;
}

int main() {
    char example_string[20] = "12345";
    /*
        Or have your own string
            scanf("%s", example_string);
    */

    printf("Converted: %i", string_to_integer(example_string));

    /*
        You can also store the value return by string_to_integer() function in a variable
            int converted = string_to_integer(example_string);

        Then, output it afterwards
            printf("Converted: %i", converted);
    */
    return 0;
}