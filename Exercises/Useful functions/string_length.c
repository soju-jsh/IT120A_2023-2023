/*
    Function
        Purpose: Gets the string length
        Return: (int) Length
*/  

#include <stdio.h>

int get_length(char string[]) {
    int length;
    for(length = 0; string[length] != '\0'; length++);
    return length;
}

int main() {
    char example_string[20] = "jsh.ncsbg";
    /*
        Or have your own string
            scanf("%s", example_string);
    */

    printf("Length: %i", get_length(example_string));

    /*
        You can also store the value return by get_length() function in a variable
            int length = get_length(example_string);

        Then, output it afterwards
            printf("Length: %i", length);
    */

    return 0;
}
