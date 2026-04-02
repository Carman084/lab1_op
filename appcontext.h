#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "status.h"
#include "bases.h"

typedef struct{
    char* input;
    char* output;
    Base sourceBase;
    Base lastBase;
    Status status;
} AppContext;

#endif // APPCONTEXT_H
