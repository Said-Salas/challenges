#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

void rnaStrand(const char *dna, char *rna, int len) {
    for (int i = 0; i < len; i++) {
        switch(dna[i]) {
            case 'G': rna[i] = 'C'; break;
            case 'C': rna[i] = 'G'; break;
            case 'T': rna[i] = 'A'; break;
            case 'A': rna[i] = 'U'; break;
        }
    }
    rna[len] = '\0';
}

bool onlyCAGT(char *strand, int len) {
    if (isAlphaString(strand)) {
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
    printf("Press Ctrl + C to exit\n");
    while (1) {
        printf("Enter sequence of DNA: ");
        char *dna = readInput();
        if (!dna) {
            fprintf(stderr, "Memory error.\n");
            break;
        }

        int len = strlen(dna);
        if (len > 0 && onlyCAGT(dna, len)) {
            strToUpper(dna);
            char *rna = malloc(len + 1);
            if (rna) {
                rnaStrand(dna, rna, len);
                printf("RNA sequence for given DNA sequence is: %s\n", rna);
                free(rna);
            }
        }
        free(dna); 
    }
    return 0;
}