#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "utils.h"
#define MAX_STRAND_LEN 40

int hammingDistance(const char *strandOne, const char *strandTwo) {
    int diff = 0;
    int len = strlen(strandOne);
    for (int i = 0; i < len; i++) {
        if (!(strandOne[i] == strandTwo[i])) {
            diff++;
        }
    }
    return diff;
}

bool onlyCAGT(char *strand) {
    if (isAlphaString(strand)) {
        int len = strlen(strand);
        for (int i = 0; i < len; i++) {
            char c = toupper((unsigned char)strand[i]);
            if (c != 'C' && c != 'A' && c != 'G' && c != 'T') {
                fprintf(stderr, "Please enter only bases C, A, G and T.\n");
                return false;
                }
        } 
        return true;
    } else {
        fprintf(stderr, "Please enter only alphabetic values.\n");
        return false;
    }
}

int main(void) {
    printf("Press CTRL + C to exit program\n");
    printf("Hamming Distance Calculator.\n");
    char strandOne[MAX_STRAND_LEN];
    char strandTwo[MAX_STRAND_LEN];
    while (1) {
        printf("Enter first strand of DNA: ");
        scanf("%39s", strandOne);
        printf("\nEnter second strand of DNA: ");
        scanf("%39s", strandTwo);
        if (strlen(strandOne) == strlen(strandTwo)) { 
            if (onlyCAGT(strandOne) && onlyCAGT(strandTwo)) {
                strToUpper(strandOne), strToUpper(strandTwo);
                int result = hammingDistance(strandOne, strandTwo);
                printf("The Hamming Distance between these strands is: %d\n", result);
            } 
        } else {
            fprintf(stderr, "Please enter two equal length strands of DNA.\n");
        }
    }
    return 0;
}