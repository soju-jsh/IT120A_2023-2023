/*
    Machine Problem #2 - Upsilon
    ====================
        | Nacasabog, Sabdani, Atienda
        | Group 4
*/

#include <stdio.h>

//  :: Declaration of Functions
// [Section 1]
int validity_check(char str[]);
int ask_user(void);

int STR_to_INT(char, char str[], int);
int str_len(char str[]);

// [Section 2]
int dBinary(char, char str[], int);
int oBinary(char str[], int);
int hBinary(char str[], int);

// [Section 3]
int bDecimal(char str[]);
void bOctal(char str[]);
void bHexadecimal(char str[]);

int main() {
    int use_again;
    int isValid;

    printf( "==================================================\n"
            "||            Programmer's Calculator           ||\n"
            "==================================================\n"
            "  Please have a suffix at the end of your input   \n"
            "  to indicate its number system. [o, h, d, b]     \n"
            "                                                  \n"
            "  Ex: 1234o - 1234 is in Octal system               ");

    do {
        char user_input[100] = "";
        char binary[100] = "";
        char input_value[100] = "";

        for (isValid = 0; isValid == 0; isValid = validity_check(user_input)) {
            printf("\n\n  Input: ");
            scanf("%s", user_input);
        };

        for (int i = 0; i < str_len(user_input) - 1; i++) {
            input_value[i] = user_input[i];
        } // input_value = user_input without suffix

        printf("  Output: \n");

        switch (user_input[str_len(user_input) - 1]) {
            case 'd':
                for (int i = 0; dBinary(' ', input_value, i) != '\0'; i++) {
                    binary[i] = dBinary(' ', input_value, i);
                }

                printf("\t%sb\n", binary);
                bOctal(binary);
                bHexadecimal(binary);
                break;
            case 'o':
                for (int i = 0; oBinary(input_value, i) != '\0'; i++) {
                    binary[i] = oBinary(input_value, i);
                }

                printf("\t%sb\n", binary);
                printf("\t%id\n", bDecimal(binary));
                bHexadecimal(binary);
                break;
            case 'h':
                for (int i = 0; hBinary(input_value, i) != '\0'; i++) {
                    binary[i] = hBinary(input_value, i);
                }

                printf("\t%sb\n", binary);
                printf("\t%id\n", bDecimal(binary));
                bOctal(binary);
                break;
            case 'b':
                for (int i = 0; i < str_len(input_value); i++) {
                    binary[i] = input_value[i];
                }

                printf("\t%id\n", bDecimal(binary));
                bOctal(binary);
                bHexadecimal(binary);
                break;
        }
    } while (use_again = ask_user());

    printf("\n  Thank you for using our program <33");
    return 0;
}

/*
    :: Functions [Section 1 - Extra Functions for conveniency]
        + validity_check()
            - [INTEGER] returns validity on input in bool

        + ask_user()
            - [INTEGER] returns user's response in bool

        + str_len()
            - [INTEGER] returns the length of a char[]

        + STR_to_INT()
            - [INTEGER] returns user string (excluding specificied last characters) in integer
*/

int str_len(char str[]) {
    int len;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}

int validity_check(char str[]) {
    int len = str_len(str);

    int error_place[20] = {};
    int num_errors = 0;

    char suffix = str[len - 1];

    int valid_suffix =
        suffix == 'd' ||
        suffix == 'o' ||
        suffix == 'b' ||
        suffix == 'h';

    char lower_bound[2] = {
        '0',
        'A'
    };

    char upper_bound[2] = {
        suffix == 'o' ? '7' : suffix == 'b' ? '1' :
            '9',
        'F'
    };

    char bLimit[32] = "1111111111111111111111111111111";
    char oLimit[12] = "17777777777";
    char dLimit[11] = "2147483647";
    char hLimit[9] = "7FFFFFFF";

    int valid_input = !(suffix >= lower_bound[0] && suffix <= upper_bound[0]) && !(suffix >= lower_bound[1] && suffix <= upper_bound[1]);

    if (len == 0) {
        printf("\n  Error: Empty input...");
        return 0;
    } else if (len == 1 && valid_suffix) {
        printf("\n  Error: Empty digit sequence before suffix...");
        return 0;
    } else if (len > 32) {
        printf("\n  Error: Exceeded input limit");
        return 0;
    } else if (!valid_suffix) {
        for (int i = 0; i < len - 1; i++) {
            if (!(str[i] >= lower_bound[0] && str[i] <= upper_bound[0]) && !(str[i] >= lower_bound[1] && str[i] <= upper_bound[1])) {
                error_place[i] = 1;
                num_errors++;
            }
        }

        printf("         ");
        for (int i = 0; i < len - 1; i++) {
            printf("%c", num_errors > 0 && error_place[i] == 1 ? '^' : ' ');
        }
        printf("%s", valid_input ? "^" : " ^?");
        printf("\n  Error: %s suffix %s", valid_input ? "Invalid" : "Missing", num_errors > 0 ? "and digit sequence.." : "");
        return 0;
    } else {
        for (int i = 0; i < len - 1; i++) {
            if (suffix == 'h') {
                if (!((str[i] >= lower_bound[0] && str[i] <= upper_bound[0]) || (str[i] >= lower_bound[1] && str[i] <= upper_bound[1]))) {
                    error_place[i] = 1;
                    num_errors++;
                }
            } else if (!(str[i] >= lower_bound[0] && str[i] <= upper_bound[0])) {
                error_place[i] = 1;
                num_errors++;
            }
        }

        if (num_errors > 0) {
            printf("         ");
            for (int i = 0; i < len - 1; i++) {
                printf("%c", error_place[i] == 1 ? '^' : ' ');
            }
            printf("\n  Error: Invalid digit sequence in\n         %s string...",
                suffix == 'd' ? "decimal" : // if 'd', then print "decimal"
                suffix == 'o' ? "octal" : // if 'o', then print "octal"
                suffix == 'h' ? "hexadecimal" : // if 'h', then print "hexidecimal"
                "binary"); // Else, it must be binary, then print "binary"
            return 0;
        }
    }
    if (suffix == 'h' && len >= 9) { // Checks input limit for h
        if (len > 9) {} else {
            for (int i = 0; i < 8; i++) {
                if (i == 0 ? !(str[i] >= '0' && str[i] <= '7') : !(str[i] >= 'A' && str[i] <= 'F') && !(str[i] >= '0' && str[i] <= '7')) {
                    printf("\n  Error: Cannot exceed %sh", hLimit);
                    return 0;
                }
            }
            return 1;
        }
        printf("\n  Error: Cannot exceed %sh", hLimit);
        return 0;
    } else if (suffix == 'o' && len >= 12) { // Checks input limit for o
        if (len > 12) {} else {
            for (int i = 0; i < 11; i++) {
                if (!(str[i] >= '0' && str[i] <= oLimit[i])) {
                    printf("\n  Error: Cannot exceed %so", oLimit);
                    return 0;
                }
            }
            return 1;
        }
        printf("\n  Error: Cannot exceed %so", oLimit);
        return 0;
    } else if (suffix == 'd' && len >= 11) { // Checks input limit for d
        if (len > 11) {} else {
            for (int i = 0; i < 10; i++) {
                if (!(str[i] >= '0' && str[i] <= dLimit[i])) {
                    printf("\n  Error: Cannot exceed %sd", dLimit);
                    return 0;
                }
            }
            return 1;
        }
        printf("\n  Error: Cannot exceed %sd", dLimit);
        return 0;
    } else if (suffix == 'b' && len == 32) { // Checks input limit for b
        for (int i = 0; i < 31; i++) {
            if (!(str[i] >= '0' && str[i] <= bLimit[i])) {
                printf("\n  Error: Cannot exceed %sb", bLimit);
                return 0;
            }
        }
        return 1;
    }
    return 1;
}

int ask_user(void) {
    char answer;
    printf("\n  Use the program again? <y/n>: ");
    scanf(" %c", & answer);
    return answer == 'y' || answer == 'Y';
}

int STR_to_INT(char digit, char str[], int excluded_last_chars) {
    if (str_len(str) == 0) {
        return (digit >= 0 && digit <= '9') ? (digit - 48) : (digit - 55);
    }

    int converted = 0;
    int len = str_len(str);
    for (int i = 0; i < len - excluded_last_chars; i++) {
        converted *= 10;
        converted += str[i] - '0';
    }

    return converted;
}

/*
    :: Functions [Section 2 - Required functions for phase 2]
        + dBinary()
            - [INTEGER] converts to binary string, returns char located at the specified index 

        + hBinary()
            - [INTEGER] converts to binary string, returns char located at the specified index

        + oBinary()
            - [INTEGER] converts to binary string, returns char located at the specified index
*/

int dBinary(char digit, char str[], int index_return) {
    int converted = digit == ' ' ? STR_to_INT(' ', str, 0) : STR_to_INT(digit, "", 0);

    char char_ret[32] = "";

    if (converted == 0) {
        char_ret[0] = '0';
    }

    for (int i = 0; converted > 0; i++) {
        char_ret[i] = converted % 2 + '0';
        converted /= 2;
    }

    for (int i = 0; i < str_len(char_ret) / 2; i++) {
        char TMP = char_ret[str_len(char_ret) - i - 1];
        char_ret[str_len(char_ret) - i - 1] = char_ret[i];
        char_ret[i] = TMP;
    }

    return char_ret[index_return];
}

int oBinary(char str[], int index_return) {
    char char_ret[32] = "";
    int index = 0;

    for (int i = 0; i < str_len(str); i++) {
        char three_bit[3] = "";

        for (int y = 0; dBinary(str[i], " ", y) != '\0'; y++) {
            three_bit[y] = dBinary(str[i], " ", y);
        }

        if (i != 0) {
            for (int y = 3; y > str_len(three_bit); y--) {
                char_ret[index++] = '0';
            }
        }

        for (int y = 0; y < 3 && three_bit[y] != '\0'; y++) {
            char_ret[index++] = three_bit[y];
        }
    }
    return char_ret[index_return];
}

int hBinary(char str[], int index_return) {
    char char_ret[36] = "";
    int index = 0;

    for (int i = 0; i < str_len(str); i++) {
        char four_bit[4] = "";

        for (int y = 0; dBinary(str[i], " ", y) != '\0'; y++) {
            four_bit[y] = dBinary(str[i], " ", y);
        }

        if (i != 0) {
            for (int y = 4; y > str_len(four_bit); y--) {
                char_ret[index++] = '0';
            }
        }

        for (int y = 0; y < 4 && four_bit[y] != '\0'; y++) {
            char_ret[index++] = four_bit[y];
        }
    }

    return char_ret[index_return];
}

/*
    :: Functions [Section 3 - Required functions for phase 2]
        + bDecimal()
            - [INTEGER] returns the equivalent value in decimal  

        + bOctal()
            - [VOID] prints the equivalent value in octal   

        + bHexadecimal()
            - [VOID] prints the equivalent value in hexadecimal
*/

int bDecimal(char str[]) {
    int decimal = 0;
    for (int i = 0; i < str_len(str); i++) {
        decimal *= 2;
        decimal += str[i] - '0';
    }
    return decimal;
}

void bOctal(char str[]) {
    char with_zeros[100] = "";
    char o[100] = "";

    int octal = 0;
    int index = 0;
    int length = 0;

    int zerosNeeded = 3 - (str_len(str) % 3 == 0 ? 3 : str_len(str) % 3);

    for (int i = 0; i < zerosNeeded; i++) {
        with_zeros[index++] = '0';
    } for (int i = 0; i < str_len(str); i++) {
        with_zeros[index++] = str[i];
    }
    
    index = 0;
    for (int i = 0; i < str_len(with_zeros) / 3; i++) {
        int three_bit = 0;
        octal *= 10;
        for (int i = 0; i < 3; i++) {
            three_bit *= 2;
            three_bit += with_zeros[index++] - '0';
        }
        octal += three_bit;
        o[length++] = three_bit >= 0 && three_bit <= 9 ? three_bit + 48 : three_bit + 55;
    }
    printf("\t%so\n", o);
}

void bHexadecimal(char str[]) {
    char with_zeros[100] = "";
    char hOutput[100] = "";

    int index = 0;
    int length = 0;

    int zerosNeeded = 4 - (str_len(str) % 4 == 0 ? 4 : str_len(str) % 4);

    for (int i = 0; i < zerosNeeded; i++) {
        with_zeros[index++] = '0';
    } for (int i = 0; i < str_len(str); i++) {
        with_zeros[index++] = str[i];
    }

    index = 0;
    for (int i = 0; i < str_len(with_zeros) / 4; i++) {
        int four_bit = 0;
        for (int i = 0; i < 4; i++) {
            four_bit *= 2;
            four_bit += with_zeros[index++] - '0';
        }
        hOutput[length++] = four_bit >= 0 && four_bit <= 9 ? four_bit + 48 : four_bit + 55;
    }
    printf("\t%sh\n", hOutput);
}