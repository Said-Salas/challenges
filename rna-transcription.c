#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void rnaStrand(const char *strand, *rna) {
    int len = strlen(strand);
    for (int i = 0; i < len; i++) {
        switch(strand[i]) {
            case 'G': rna[i] = 'G'; break;
            case 'C': rna[i] = 'G'; break;
            case 'T': rna[i] = 'A'; break;
            case 'A': rna[i] = 'U'; break;
        }
    }
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
    printf("Press Ctrl + C to exit\n");
    while (1) {
        char *dna = malloc(41 * sizeof(char)); 
        char *rna = malloc(41 * sizeof(char));
        int storedBases = 0;
        printf("Enter sequence of DNA: ");
        scanf("%s", dna);
        if (onlyCAGT(dna)); {
            strToUpper(dna);
            rnaStrand(dna, rna);
            printf("RNA sequence for given DNA sequence is: %s", rna);
        }
    }
    return 0;
}