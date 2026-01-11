#include <stdio.h>
#include <strlen.h>
#include <utils.h>
#define MAX_LEN 41

int binToDec(const char *str, int len) {
    for (int i = 0; i < len; i++) {
        
    }
}

bool onlyZeroOne(const char *str, int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] != '0' || str[i] != '1') {
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
        int len = strlen(str);
        if (!isNumeric(binary) || !onlyZeroOne(binary, len)) {
            fprintf(stderr, "Please enter only 0s and 1s.\n");
            free(binary);
            continue;
        }
        
    }
    return 0;
}
