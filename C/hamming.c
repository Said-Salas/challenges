#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#define MAX_STRAND_LEN 40

int hammingDistance(const char *strandOne, const char *strandTwo) {
    int diff = 0;
    for (int i = 0; i < strlen(strandOne); i++) {
        if (!(strandOne[i] == strandTwo[i])) {
            diff++;
        }
    }
    return diff;
}

bool onlyCAGT(const char *strand) {
    for (int i = 0; i < strlen(strand); i++) {
        if (strand[i] == 'C' || strand[i] == 'A' || strand[i] == 'G' || strand[i] == 'T') {
            return true;
        }
    } 
    return false;
}

int main(void) {
    printf("Hamming Distance Calculator.\n");
    char strandOne[MAX_STRAND_LEN];
    char strandTwo[MAX_STRAND_LEN];
    while (1) {
        printf("Enter first strand of DNA: ");
        scanf("%39s", strandOne);
        printf("\nEnter second strand of DNA: ");
        scanf("%39s", strandTwo);
        if ((strlen(strandOne) == strlen(strandTwo)) && (isAlphaString(strandOne) && isAlphaString(strandTwo))) { 
            strToUpper(strandOne); strToUpper(strandTwo);
            if (onlyCAGT(strandOne) && onlyCAGT(strandTwo)) {
                int result = hammingDistance(strandOne, strandTwo);
                printf("The Hamming Distance between these strands is: %d\n", result);
                continue;
            } else {
                fprintf(stderr, "Please enter only bases C, A, G and T.\n");
            }
        } else {
            fprintf(stderr, "Please enter two equal length strands of DNA.\n");
            continue;
        }
    }
    return 0;
}