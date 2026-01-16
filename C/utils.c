#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h> //for type 'size_t'
#include "utils.h"

char *readInput(void) {
    int capacity = 10;
    int length = 0;
    char *buffer = malloc(capacity);

    if (!buffer) return NULL;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *newBuffer = realloc(buffer, capacity);
            if (!newBuffer) {
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
        }
        buffer[length++] = (char)c;
    }
    buffer[length] = '\0';
    return buffer;
}


bool isAlphaString(const char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

 bool isNumeric(const char *str) { 
    if (!str || *str == '\0') return false;
    int i = 0;

    if (str[0] == '-') {
        i++;

        if (str[i] == '\0') return false;
    }

    for (; str[i] != '\0'; i++) {
        if(!isdigit((unsigned char)str[i])) {
            return false;
        }
    }
    return true;
 }

 int stringToInt(const char *str) {
    int result = 0;
    int i = 0;
    
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; i++) {
        result = (result * 10) + (str[i] - '0');
    }
    return result * sign;
 }

void strToLower(char *str) {
    for (; *str; ++str) *str = (char)tolower((unsigned char)*str);
}
void strToUpper(char *str) {
    for (; *str; ++str) *str = (char)toupper((unsigned char)*str);
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