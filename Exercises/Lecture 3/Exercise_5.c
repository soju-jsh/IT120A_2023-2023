/*
    Lecture 3
    Exercise: Bubble sort algorithm on an array of ten or more integers elements
*/

#include <stdio.h>

int main() {
    // Array of ten integer elements
    int array[10] = {1, 4, 5, 3, 7, 2, 10, 9, 6, 8};

    // Bubble sort
    for (int i = 0; i < 9; i++) {
        for (int y = 0; y < 9 - i; y++) {
            int TMP = array[y];
            if (array[y] > array [y + 1]) {
                array[y] = array [y + 1];
                array [y + 1] = TMP;
            }
        }
    }
    
    // Output
    for (int i = 0; i < 10; i++) {
        printf("%i ", array[i]);
    }

    return 0;
}