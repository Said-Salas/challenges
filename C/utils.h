#ifndef UTILS_H //this file contains the declarations of the functions that are available for other programs to use.
#define UTILS_H
#include <stdbool.h>

char *readInput(void);
bool isAlphaString(const char *string);
void strToLower(char *s);
void strToUpper(char *s);
void trimString(char *str);
void clearBuffer(void);

#endif