#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h> //for type 'size_t'
#include "utils.h"

bool isAlphaString(const char *string) {
    for(int i = 0; string[i] != '\0'; i++) {
        if(!isalpha(string[i])) {
            return false;
        }
    }
    return true;
}

void strToLower(char *s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}
void strToUpper(char *s) {
    for (; *s; ++s) *s = (char)toupper((unsigned char)*s);
}

void trimString(char *str) {
    char *start = str;
    while (*start && isspace((unsigned char)*start));
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }

    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}