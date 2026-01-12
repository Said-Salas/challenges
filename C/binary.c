#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <math.h>
#define MAX_LEN 41

void binToDec(int *digit, const char *str, int len) {
    for (int i = 0; i < len; i++) {
        int bin = str[i] - '0';
        digit += bin * (int)pow(2, len - (i + 1));
    }
}

bool onlyZeroOne(const char *str, int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

int main(void) {
    printf("Press Ctrl + C to exit program.\n");
    while (1) {
        int digit = 0;
        printf("Enter binary number: ");
        char *binary = readInput();
        if (!binary) {
            fprintf(stderr, "Memory error.\n");
            break;
        }
        int len = strlen(binary);
        if (!isNumeric(binary) || !onlyZeroOne(binary, len)) {
            fprintf(stderr, "Please enter only 0s and 1s.\n");
            free(binary);
            continue;
        }
        binToDec(&digit, binary, len);
        printf("Binary %s is number %d\n", binary, digit);
    }
    return 0;
}
