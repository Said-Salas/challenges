#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"


void countEggs(int *number, int *eggs) {
    while (number != 0) {
        if (*number % 2 == 1) {
            *eggs += 1;
        }
        *number /= 2;
    }
}

int main(void) {
    printf("Press Ctrl + C to exit program.\n");
    while (1) {
        printf("Enter number on display case: ");
        char *numberText = readInput();
        if (!isNumeric(numberText)) {
            fprintf(stderr,  "Please enter only 0s and 1s\n");
            free(numberText);
            continue;
        } 
        int number = stringToInt(numberText);
        int eggs = 0;
        countEggs(&number, &eggs);
        printf("Eggs on nest: %d\n", eggs);
        free(numberText);
    }
    return 0;
}