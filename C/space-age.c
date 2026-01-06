#include <stdio.h>
#include <string.h>
#include "utils.h"
#include <ctype.h>
#include <stdbool.h>
#define MAX_LEN 30

const char *planets[] = {
    "mercury", "venus", "earth", "mars", "jupiter", "saturn",
    "uranus", "neptune"
};

const float orbitalPeriod[] = {
    0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846,
    164.79132 
};

int planetsLength = sizeof(planets) / sizeof(planets[0]);

float calculateAge(int age, const char *planet) {
    for (int i = 0; i < planetsLength; i++) {
        if (strcmp(planet, planets[i]) == 0) {
            return age / orbitalPeriod[i];
        }
    }
    return -1;
}

int main(void) {
    printf("Press Ctrl + C to end program\n");
    printf("Interplanetary Age Calculator\n");
    printf("Calculate your age in any planet in our Solar System.\n");
    int age = 0;
    char planet[MAX_LEN];

    while(1) {
        printf("Enter your age in Earth years: ");

        if (!(scanf("%d", &age) == 1)) {
            fprintf(stderr, "Please enter a valid age.\n");
            clearBuffer();
            continue;
        } 

        clearBuffer();

        if (age > 0) {
            printf("Enter name of Solar System planet: ");
            scanf("%29s", planet); //Adding 29 for a max length of 30 (30 was specified by me) prevents a buffer overflow.
            clearBuffer();
            strToLower(planet);
            float newAge = calculateAge(age, planet);
            if (newAge != -1) {
                char *trimmedPlanet = planet + 1;
                char c = toupper((unsigned char)planet[0]);
                printf("Your age of %d years in Earth becomes an age of %.2f years in %c%s\n", age, newAge, c, trimmedPlanet);
            } else {
                fprintf(stderr, "Planet does not exist in our Solar System.\n");
            }
        } else {
            fprintf(stderr, "Please enter an age greater than 0 years.\n");
        }
    }
}
