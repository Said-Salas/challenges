#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#define MAX_LEN 41

int binToDec(const char *str, int len) {
    int digit = 0;
    for (int i = 0; i < len; i++) {
       digit = (digit * 2) + (str[i] - '0');
    }
    return digit;
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
        printf("Enter binary number: ");
        char *binary = readInput();
        if (!binary) {
            fprintf(stderr, "Memory error.\n");
            break;
        }
        int len = strlen(binary);
        if (!onlyZeroOne(binary, len)) {
            fprintf(stderr, "Please enter only 0s and 1s.\n");
            free(binary);
            continue;
        }
        int digit = binToDec(binary, len);
        printf("Binary %s is number %d\n", binary, digit);
        free(binary);
    }
    return 0;
}
