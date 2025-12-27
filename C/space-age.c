#include <stdio.h>
#include "utils.h"

int main(void) {
    printf("Interplanetary Age Calculator\n");
    int age = 0;

    while(1) {
        printf("Enter your age in Earth years: ");

        if(!(scanf("%d", &age) == 1)) {
            fprintf(stderr, "Please enter a valid age.\n");
            clearBuffer();
            continue;
        } 
    }
}