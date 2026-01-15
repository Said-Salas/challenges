#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

int binToDec(const char *str, int len) {
    int digit = 0;
    for (int i = 0; i < len; i++) {
       digit = (digit * 2) + (str[i] - '0');
    }
    return digit;
}

bool countOnes(const char *str, int len, *eggs) {
    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    for (int i = 0; i < len; i++) {
        if (str[i] == '1') {
            ones += 1;
        }
    }
    return true;
}

int main(void) {
    printf("Press Ctrl + C to exit program.\n");
    while (1) {
        printf("Enter sequence of nest boxes: ");
        char *boxes = readInput();
        int len = strlen(boxes);
        int eggs = 0;
        if (!countOnes(boxes, len, &eggs)) {
            fprintf(stderr,  "Please enter only 0s and 1s\n");
            free(boxes);
            continue;
        } 
        printf("Binary %s is number &d. Actual eggs in coop are %d", boxes, binToDec(boxes, len), eggs);

        int digit = binToDec(boxes, len);

    }
    return 0;
}