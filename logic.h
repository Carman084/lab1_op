#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"
#include <string.h>
#include "entrypoint.h"
#include "memory.h"
#include "validator.h"

enum {
    HALVING = 2,
    DIFFERENCE_ASCII = 32,
    LEN = 33
};

void convertInput(AppContext* context);
void updateInput(AppContext* context, AppParams* params);
void setLastBase(AppContext* context, Base base);
void freeContext(AppContext* context);
void updateSourceBase(AppContext* context, AppParams* params);
void updateLastBase(AppContext* context, AppParams* params);
void initContext(AppContext* context);
#endif // LOGIC_H
