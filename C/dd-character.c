#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <time.h>
#include <math.h>
#define NUM_ATTRIBUTES 7
#define NUM_ROLLS 4
#define PICKED_ROLLS 3

void arrHighests(int *arrayOne, int *arrayTwo) {
    for (int i = 0; i < NUM_ROLLS - 1; i++) arrayTwo[i] = arrayOne[i] > arrayOne[i + 1] ? arrayOne[i] : arrayOne[i + 1];
}

void sumHighests(int *array, int *sum) {
    for(int i = 0; i < PICKED_ROLLS; i++) *sum += array[i];
}

int main(void) {
    printf("Ctrl + C to exit.\n");
    while (1) {
        printf("Type 'Yes' to generate new character.\n");
        char *keyword = readInput(); strToLower(keyword);
        if (!(strcmp(keyword, "yes") == 0)) {
           break;
        } 
        int abilities[NUM_ATTRIBUTES]; int rolls[NUM_ROLLS]; int roll = 0; int highests[PICKED_ROLLS]; int value = 0;
        for (int i = 0; i < NUM_ATTRIBUTES - 1; i++) {
            for (int i = 0; i < NUM_ROLLS; i++) {
                srand(time(NULL));
                roll = (rand() % 6) + 1;
                printf("%d\n", roll);
                rolls[i] = roll;
            }
            arrHighests(rolls, highests); sumHighests(highests, &value);
            if (i == 2) abilities[i] = (value - 10) / 2;
            if (i == 6) abilities[i] = abilities[2] + 10;
            else abilities[i] = value;
            value = 0;
        }
        printf("\nNew character generated.\n"); printf("Strength: %d\n", abilities[0]); printf("Dexterity: %d\n", abilities[1]);
        printf("Constitution Modifier: %d\n", abilities[2]); printf("Intelligence: %d\n", abilities[3]); printf("Wisdom: %d\n", abilities[4]);
        printf("Charisma: %d\n", abilities[5]); printf("Hitpoints: %d\n\n", abilities[6]);
    }
    return 0;
}