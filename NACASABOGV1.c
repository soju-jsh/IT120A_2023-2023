/*
    Machine Problem #2 - Upsilon
    ====================
        | Nacasabog, Sabdani, Atienda
        | Group 4
*/

#include <stdio.h>

//  :: Declaration of Functions
// [Section 1]
void getUser_input(void);
int validity_check(char str[]);
int ask_user(void);

int STR_to_INT(char str[], int);
int str_len(char str[]);
int str_cmp(char str1[], char str2[]);

int power(int, int);
int get_places(int);

// [Section 2]
int dBinary(int);
int oBinary(char str[]);
int hBinary(char str[]);

// [Section 3]
int bDecimal(int);
int bOctal(int);
void bHexadecimal(int);

//  :: Declaration of Global Variables
char user_input[100] = "";

int main() {
    int use_again;
    int isValid;
    int binary;

    printf( "==================================================\n"
            "||            Programmer's Calculator           ||\n"
            "==================================================\n"
            "  Please have a suffix at the end of your input   \n"
            "  to indicate its number system. [o, h, d, b]     \n"
            "                                                  \n"
            "  Ex: 1234o - 1234 is in Octal system               ");

    do {
        for (isValid = 0; isValid == 0; isValid = validity_check(user_input)) {
            getUser_input();
        };

        printf("  Output: \n");

        switch (user_input[str_len(user_input) - 1]) {
            case 'd':
                printf("\t%ib\n", binary = dBinary(STR_to_INT(user_input, 1)));
                printf("\t%io\n", bOctal(binary));
                bHexadecimal(binary);
                break;
            case 'o':
                printf("\t%ib\n", binary = oBinary(user_input));
                printf("\t%id\n", bDecimal(binary));
                bHexadecimal(binary);
                break;
            case 'h':
                printf("\t%ib\n", binary = hBinary(user_input));
                printf("\t%id\n", bDecimal(binary));
                printf("\t%io\n", bOctal(binary));
                break;
            case 'b':
                binary = STR_to_INT(user_input, 1);
                printf("\t%id\n", bDecimal(binary));
                printf("\t%io\n", bOctal(binary));
                bHexadecimal(binary);
                break;
        }

        use_again = ask_user();
    } while (use_again);

    printf("\n  Thank you for using our program <33");
    return 0;
}

/*
    :: Functions [Section 1 - Extra Functions for conveniency]
        + getUser_input() 
            - get user's input 

        + validity_check() 
            - check's input and suffix validity 

        + ask_user() 
            - asks the user if user wants to use program again

        + str_len() 
            - returns the string length of the array 

        + STR_to_INT() 
            - returns the integer type of user string input excluding the suffix

        + str_cmp()
            - compares two strings

        + str_cpy()
            - copys str2 and pastes to str1

        + power()
            - calculate number with given exponent

        + get_places()
            - gets the number of digits
*/

void getUser_input(void) {
    printf("\n\n  Input: ");
    scanf("%s", user_input);
}

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
        suffix == 'o' ? '7' : suffix == 'b' ? '1' : '9',
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
        if (len > 9) {
        } else {
            for (int i = 0; i < 8; i++) {
                if (i == 0 ?  !(str[i] >= '0' && str[i] <= '7') : !(str[i] >= 'A' && str[i] <= 'F') && !(str[i] >= '0' && str[i] <= '7')){
                    printf("\n  Error: Cannot exceed %sh", hLimit);
                    return 0;
                }
            }
            return 1;            
        }
        printf("\n  Error: Cannot exceed %sh", hLimit);
        return 0;     
    } else if (suffix == 'o' && len >= 12) { // Checks input limit for o
        if (len > 12) {
        } else {
            for (int i = 0; i < 11; i++) {
                if (!(str[i] >= '0' && str[i] <= oLimit[i])){
                    printf("\n  Error: Cannot exceed %so", oLimit);
                    return 0;
                }
            }
            return 1;            
        }
        printf("\n  Error: Cannot exceed %so", oLimit);
        return 0;        
    } else if (suffix == 'd' && len >= 11) { // Checks input limit for d
        if (len > 11) {
        } else {
            for (int i = 0; i < 10; i++) {
                if (!(str[i] >= '0' && str[i] <= dLimit[i])){
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
            if (!(str[i] >= '0' && str[i] <= bLimit[i])){
                printf("\n  Error: Cannot exceed %sb", bLimit);
                return 0;
            }
        }
        return 1;    
    }
}

int ask_user(void) {
    char answer;
    printf("\n  Use the program again?: ");
    scanf(" %c", & answer);
    return answer == 'y' || answer == 'Y';
}

int STR_to_INT(char str[], int excluded_last_chars) {
    int converted = 0;
    int len = str_len(str);
    for (int i = 0; i < len - excluded_last_chars; i++) {
        converted *= 10;
        converted += str[i] - '0';
    }
    return converted;
}

int str_cmp(char str1[], char str2[]) {
    if (str_len(str1) != str_len(str2)) {
        return 0;
    }
    int reached;
    for (int i = 0; str1[i] == str2[i] && i < str_len(str1); i++, reached = i);
    return reached == str_len(str1);
}

int get_places(int num) {
    int places = 0;
    for (int i = num; i > 0; i /= 10) {
        places++;
    }
    return places;
}

int power(int num, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= num;
    }
    return result;
}

/*
    :: Functions [Section 2 - Required functions for phase 2]
        + dBinary()
            - receives decimal in string, string to integer, returns Binary equivalent

        + hBinary()
            - receives hexadecimal in string, string to integer, returns Binary equivalent

        + oBinary()
            - receives octal in string, string to integer, returns Binary equivalent
*/

int dBinary(int converted) {
    int number = 0;
    for (int place = 1; converted > 0; converted /= 2) {
        number += (converted % 2) * place;
        place *= 10;
    }
    return number;
}

int oBinary(char str[]) {
    char binary[36] = "";
    int len = str_len(str);
    int suffix_index = len - 1;
    int index = 0;
    int places;
    int converted;
    for (int i = 0; i < suffix_index; i++) {
        places = get_places(dBinary(str[i] - '0'));
        if (i != 0) {
            for (int y = places; y < 3; y++) {
                binary[index++] = '0';
            }
        }
        for (int exp = places - 1; exp >= 0; exp--) {
            binary[index++] = ((exp == places - 1 ? dBinary(str[i] - '0') : (dBinary(str[i] - '0') % power(10, exp + 1))) / power(10, exp)) + '0';
        }
    }
    converted = STR_to_INT(binary, 0);
    return converted;
}

int hBinary(char str[]) {
    char binary[36] = "";
    int len = str_len(str);
    int suffix_index = len - 1;
    int index = 0;
    int places;
    int converted;
    for (int i = 0; i < suffix_index; i++) {
        int ascii = str[i] >= '0' && str[i] <= '9' ? str[i] - 48 : str[i] - 55;

        places = get_places(dBinary(ascii));
        if (i != 0) {
            for (int y = places; y < 4; y++) {
                binary[index++] = '0';
            }
        }
        for (int exp = places - 1; exp >= 0; exp--) {
            binary[index++] = ((exp == places - 1 ? dBinary(ascii) : (dBinary(ascii) % power(10, exp + 1))) / power(10, exp)) + '0';
        }
    }
    converted = STR_to_INT(binary, 0);
    return converted;
}

/*
    :: Functions [Section 3 - Required functions for phase 2]
        + bDecimal()
            - Receives binary, returns Decimal equivalent

        + bOctal()
            - Receives binary, returns Octal equivalent 

        + bHexadecimal()
            - Receives binary, returns Hexadecimal equivalent 
*/

int bDecimal(int binary) {
    char string[36] = "";
    int places = get_places(binary);
    int decimal = 0;
    int index = 0;
    for (int exp = places - 1; exp >= 0; exp--) {
        string[index++] = ((exp == places - 1 ? binary : (binary % power(10, exp + 1))) / power(10, exp)) + '0';
    }
    for (int i = 0; i < str_len(string); i++) {
        decimal *= 2;
        decimal += string[i] - '0';
    }
    return decimal;
}

int bOctal(int binary) {
    char string[36] = "";
    int places = get_places(binary);
    int index = 0;
    int octal = 0;
    for (int exp = places - 1; exp >= 0; exp--) {
        string[index++] = ((exp == places - 1 ? binary : (binary % power(10, exp + 1))) / power(10, exp)) + '0';
    }
    index = 0;
    for (int i = 3 - str_len(string) % 3; i > 0; i--) {
        string[index++] = '0';
    }
    for (int exp = places - 1; exp >= 0; exp--) {
        string[index++] = ((exp == places - 1 ? binary : (binary % power(10, exp + 1))) / power(10, exp)) + '0';
    }
    for (int i = 0; i < str_len(string) / 3; i++) {
        char divided_string[4] = "";

        for (int y = 0, z = i * 3; y < 3; y++) {
            divided_string[y] = string[z++];
        }
        octal *= 10;
        octal += bDecimal(STR_to_INT(divided_string, 0));
    }

    return octal;
}

void bHexadecimal(int binary) {
    char string[36] = "";
    int places = get_places(binary);
    int index = 0;
    for (int exp = places - 1; exp >= 0; exp--) {
        string[index++] = ((exp == places - 1 ? binary : (binary % power(10, exp + 1))) / power(10, exp)) + '0';
    }
    index = 0;
    for (int i = 4 - str_len(string) % 4; i > 0; i--) {
        string[index++] = '0';
    }
    for (int exp = places - 1; exp >= 0; exp--) {
        string[index++] = ((exp == places - 1 ? binary : (binary % power(10, exp + 1))) / power(10, exp)) + '0';
    }
    printf("\t");
    for (int i = 0; i < str_len(string) / 4; i++) {
        char divided_string[5] = "";

        for (int y = 0, z = i * 4; y < 4; y++) {
            divided_string[y] = string[z++];
        }
        int output = bDecimal(STR_to_INT(divided_string, 0));
        printf("%c", output >= 0 && output <= 9 ? output + 48 : output + 55);
    }
    printf("h");
}
