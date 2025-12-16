#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

const char *colors[] = {
    "black", "brown", "red", "orange", "yellow", 
    "green", "blue", "violet", "grey", "white"
};

int numColors = sizeof(colors) / sizeof(colors[0]);

int colorCode(const char *str) {
   for (int i = 0; i < numColors; i++) {
        if (strcmp(str, colors[i]) == 0) {
            return i;
        }
   }
   return -1;
}

int main(void) { //this function takes zero arguments
    char color[30];
    int value = 0;
    int *codeArray = NULL; 
    int numColors = 0;
    while (1) {
        printf("Resistor color calculator\n"
                "Black: 0, Brown: 1, Red: 2, Orange: 3, Yellow: 4, Green: 5, "
                "Blue: 6, Violet: 7, Grey: 8, White: 9\n"
                "Enter color: ");
        scanf("%s", color);
        if (!isAlphaString(&color)) {
            fprintf(stderr, "Please enter valid colors.");
            continue;
        }
        if (numColors < 2){
            strToLower(color);
            value = colorCode(color);
            if (value == -1) {
                fprintf(stderr, "Color does not have assigned value. Enter another color.");
                continue;
            }
            int *temp = realloc(codeArray, (numColors + 1) * sizeof(int));
            if (!temp) {
                fprintf(stderr, "Memory allocation failed, try again\n");
                return -1;
            }
            codeArray = temp;
            codeArray[numColors++] = value;
        } else {
            printf("Resistor code: %d%d", codeArray[0], codeArray[1]);
            numColors = 0;
        }
    }
    return 0; //non-zero values signal an error
}

// Instructions
// If you want to build something using a Raspberry Pi, you'll probably use resistors. For this exercise, you need to know two things about them:

// Each resistor has a resistance value.
// Resistors are small - so small in fact that if you printed the resistance value on them, it would be hard to read.
// To get around this problem, manufacturers print color-coded bands onto the resistors to denote their resistance values. Each band has a position and a numeric value.

// The first 2 bands of a resistor have a simple encoding scheme: each color maps to a single number. For example, if they printed a brown band (value 1) followed by a green band (value 5), it would translate to the number 15.

// In this exercise you are going to create a helpful program so that you don't have to remember the values of the bands. The program will take color names as input and output a two digit number, even if the input is more than two colors!

// The band colors are encoded as follows:

// black: 0
// brown: 1
// red: 2
// orange: 3
// yellow: 4
// green: 5
// blue: 6
// violet: 7
// grey: 8
// white: 9
// From the example above: brown-green should return 15, and brown-green-violet should return 15 too, ignoring the third color.