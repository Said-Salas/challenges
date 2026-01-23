#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void phraseBuilder(int number, char *str) {
    if (number % 3 == 0) {
        strcat(str, "Pling");
    }
    if (number % 5 == 0) {
        strcat(str, "Plang");
    }
    if (number % 7 == 0) {
        strcat(str, "Plong");
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
        char phrase[40] = "";
        phraseBuilder(number, phrase);
        if (!(strlen(phrase) > 0)) {
            printf("%d\n", number);
        } else {
            printf("%s\n", phrase);
        }
        free(numberText);
    }
    return 0;
}