#include "entrypoint.h"
#include "logic.h"
#include "validator.h"

void doOperation(Operation operation, AppContext* context, AppParams* params){
    switch (operation){
    case CONVERT:
        convertInput(context);
        break;
    case CHECK_ERROR:
        validateInput(context);
        break;
    case UPDATE_INPUT:
        updateInput(context, params);
        break;
    case UPDATE_SOURCE_BASE:
        updateSourceBase(context, params);
        break;
    case UPDATE_LAST_BASE:
        updateLastBase(context, params);
        break;
    }
}
