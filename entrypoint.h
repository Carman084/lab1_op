#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "appcontext.h"

typedef enum {
    CONVERT,
    CHECK_ERROR,
    UPDATE_INPUT,
    UPDATE_SOURCE_BASE,
    UPDATE_LAST_BASE
} Operation;

typedef struct {
    Base sourceBase;
    Base lastBase;
    const char* input;
} AppParams;

void doOperation(Operation operation, AppContext* context, AppParams* params);
#endif // ENTRYPOINT_H
