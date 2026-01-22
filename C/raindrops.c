#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void phraseBuilder(int number, *str) {
    if (number % 3 == 0) {
        phrase = "Pling";
    }
    if (number % 5 == 0) {
        phrase += "Plang";
    }
    if (phrase % 7 == 0) {
        phrase += "Plong"
    }
}

int main(void) {
    printf("Press Ctrl + C to exit\n");

    while (1) {
        printf("Enter number: ");
        char *numberText = readInput();
        if (!isNumeric(numberText)) {
            fprintf(stderr, "Please enter a number only\n");
            free(numberText);
            continue;
        }
        int number = stringToInt(numberText);
        char *phrase = "";
        phraseBuilder(number, phrase);
        if ()
        
        free(numberText);
    }

    return 0;
}