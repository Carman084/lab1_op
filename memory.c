#include "memory.h"

char* allocStr(int len){
    return (char*)malloc((len + 1) * sizeof(char));
}

void freeStr(char* str){
    if (str)
        free(str);
}
