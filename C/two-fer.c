#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(void) {
    printf("Press Ctrl + C to exit program.\n");

    while (1) {
        printf("Enter name of person in the queue. If not known, just hit enter: ");
        char *name = readInput();
        if(!(name[0] == '\0')) {
            printf("One for %s, one for me\n", name);
        } else {
            printf("One for you, one for me\n");
        }
    }

    return 0;
}