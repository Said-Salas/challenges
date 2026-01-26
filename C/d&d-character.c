#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <string.h>
#include <time.h>
#define NUM_SKILLS 6
#define NUM_ROLLS 4
#define PICKED_ROLLS 3

typedef struct {
    int strength;
    int dexterity;
    int constitutionModifier;
    int intelligence;
    int wisdom;
    int charisma;
    int hitpoints;
} Character;

void *arrHighests(int *arrayOne, int arrayTwo) {
    for (int i = 0; i < NUM_ROLLS - 1; i++) arrayTwo[i] = arrayOne[i] > arrayOne[i + 1] ? arrayOne[i] : arrayOne[i + 1];
}

void sumHighests(int *array, int added) {
    for(int i = 0; i < PICKED_ROLLS; i++) added += array[i];
}

int main(void) {
    printf("Ctrl + C to exit.\n");
    while (1) {
        printf("Type 'Yes' to generate new character.\n");
        char *keyword = readInput(); strToLower(keyword);
        if (!(strcmp(keyword, "yes") == 0)) {
           break;
        } 
        Character hero;
        int abilities[NUM_SKILLS]; int rolls[NUM_ROLLS]; int roll = 0; int highests[PICKED_ROLLS]; int sum = 0;
        for (int i = 0; i < NUM_SKILLS; i++) {
            for (int i = 0; i < NUM_ROLLS; i++) {
                srand(time(NULL));
                roll = (rand() % 6) + 1;
                rolls[i] = roll;
            }
            arrHighests(rolls, highests); sumHighests(highests, &sum);
        }
    }
    return 0;
}