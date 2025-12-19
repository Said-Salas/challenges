#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAX_COLOR_LEN 30

const char *colors[] = {
    "black", "brown", "red", "orange", "yellow", 
    "green", "blue", "violet", "grey", "white"
};

int totalColorsLength = sizeof(colors) / sizeof(colors[0]);

int colorCode(const char *str) {
   for (int i = 0; i < totalColorsLength; i++) {
        if (strcmp(str, colors[i]) == 0) {
            return i;
        }
   }
   return -1;
}

int main(void) { 
    printf("Press Ctrl + C to exit whole program.\n");
    printf("Type \'done\' to print resulting code.\n");
    char color[MAX_COLOR_LEN];
    int value = 0;
    int codeArray[2]; 
    int numColors = 0;
    while (1) {
        printf("\nResistor color calculator.\n"
                "Black: 0, Brown: 1, Red: 2, Orange: 3, Yellow: 4, Green: 5, "
                "Blue: 6, Violet: 7, Grey: 8, White: 9\n");
        printf("Enter color %d", numColors + 1);
        scanf("%s", color);
        if (numColors < 2) {
            if (!isAlphaString(color)) {
                fprintf(stderr, "Please enter valid colors.\n");
                continue;
            }
            strToLower(color);
            value = colorCode(color);
            if (value == -1) {
                fprintf(stderr, "Color does not have assigned value. Enter another color.\n");
                continue;
            }
            codeArray[numColors++] = value;
        }
        if (strcmp(color, "done") == 0) {
            printf("Resistor code: %d%d\n", codeArray[0], codeArray[1]);
            numColors = 0;
        } 
    }
    return 0; 
}

