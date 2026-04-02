#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

enum {
    INCREASE_CAPACITY = 2

};

char* allocStr(int len);
char* reallocStr(char* str, int* capacity, int len);
char* reallocLastStr(char* str, int capacity, int len);
void freeStr(char* str);

#endif // MEMORY_H
