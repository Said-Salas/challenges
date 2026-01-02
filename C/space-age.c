#include <stdio.h>
#include "utils.h"
#include <ctype.h>
#define MAX_LEN 30

int calculateAge(int age, const char *planet) {
    char c = toupper((unsigned char)planet[0]);
    switch(c) {
        case 'M':
            if (toupper((unsigned char)planet[1]) == 'E') {
                return age / 1.8808158;
            }
    }
}

int main(void) {
    printf("Interplanetary Age Calculator\n");
    printf("Calculate your age in any planet in our Solar System.\n");
    int age = 0;
    char planet[MAX_LEN];

    while(1) {
        printf("Enter your age in Earth years: ");

        if(!(scanf("%d", &age) == 1)) {
            fprintf(stderr, "Please enter a valid age.\n");
            clearBuffer();
            continue;
        } 

        printf("Enter Solar System planet: ");
        scanf("%29s", planet);


    }
}