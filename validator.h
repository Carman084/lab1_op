#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "status.h"
#include "bases.h"
#include "appcontext.h"
#include "limits.h"
#include <ctype.h>

enum {
    HEX_OFFSET = 10
};

void validateInput(AppContext* context);

#endif // VALIDATOR_H
