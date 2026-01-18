#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

int main(void) {
    printf("Press Ctrl + C to exit program.\n");

    while (1) {
        printf("Enter name of person in the queue. If not known, just hit enter: ");
        char *name = readInput();
        printf("One for %s, one for me.\n", (name && *name) ? name : "you");
        free(name);
    }

    return 0;
}