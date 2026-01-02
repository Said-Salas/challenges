#include <stdio.h>
#include "utils.h"
#include <ctype.h>
#define MAX_LEN 30

int calculateAge(int age, const char *planet) {
    char c = toupper((unsigned char)planet[0]);
    switch(c) {
        case 'M':
            if (toupper((unsigned char)planet[1]) == 'E') {
                return age / 0.2408467;
            } else {
                return age / 1.8808158;
            } 
        case 'V':
            return age / 0.61519726;
        case 'E':
            return age;
        case 'J':
            return age / 11.862615;
        case 'S':
            return age / 29.447498;
        case 'U':
            return age / 84.016846;
        case 'N':
            return age / 164.79132;
        default:
            return -1;
    }
}

int main(void) {
    printf("Interplanetary Age Calculator\n");
    printf("Calculate your age in any planet in our Solar System.\n");
    int age = 0;
    char planet[MAX_LEN];

    while(1) {
        printf("Enter your age in Earth years: ");

        if !(scanf("%d", &age) == 1) {
            fprintf(stderr, "Please enter a valid age.\n");
            clearBuffer();
            continue;
        } 

        if (age > 0) {
            printf("Enter name of Solar System planet: ");
            scanf("%29s", planet); //Adding 29 for a max length of 30 (30 was specified by me) prevents a buffer overflow.
            clearBuffer()
            int newAge = calculateAge(&age, planet);
            if (newAge != -1) {
                planet[0] = toupper((unsigned char)planet[0]);
                printf("Your age of %d years in Earth becomes an age of %d years in %s\n", age, newAge, planet);
            } else {
                fprintf(stderr, "Planet does not exist in our Solar System,\n");
            }
        } else {
            fprintf(stderr, "Please enter an age greater than 0 years.\n");
        }
    }
}
