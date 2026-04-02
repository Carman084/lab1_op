#include "validator.h"

Status checkEmptyInput(char* input){
    Status status = OK;
    if (!input || !*input)
        status = ERROR_EMPTY_INPUT;
    return status;
}

int checkForBin(char c){
    return c == '0' || c == '1';
}

int checkForHex(char c){
    return isdigit(c) || (c >= 'A' && c <= 'F');
}

int checkValidChar(char c, Base base){ //на несколько маленьких через switch
    int isValid = 0;
    switch(base){
    case BASE_BIN:
        isValid = checkForBin(c);
        break;
    case BASE_DEC:
        isValid = isdigit(c);
        break;
    case BASE_HEX:
        isValid = checkForHex(c);
    }
    return isValid;
}

Status checkSymbols(char* input, Base base){
    int i = 0;
    Status status = OK;
    if ((input[i] == '+' || input[i] == '-') && base == BASE_DEC)
        i++;
    while (input[i] && status == OK){
        if (!checkValidChar(input[i], base))
            status = ERROR_INVALID_SYMBOL;
        i++;
    }
    return status;
}

Status checkRange(const char* input, Base base){
    long long result = 0;
    int start = (*input == '-' && base == BASE_DEC) ? 1 : 0;
    Status status = OK;
    for (int i = start; input[i]; i++) {
        int digit = isdigit(input[i]) ? input[i] - '0' : input[i] - 'A' + HEX_OFFSET;
        result = result * base + digit;
        if (result > UINT_MAX || (result > INT_MAX && base == BASE_DEC))
            status = ERROR_OUT_OF_RANGE;
    }
    return status;
}

void validateInput(AppContext* context){
    Status status = checkEmptyInput(context->input);
    if (status == OK)
        status = checkSymbols(context->input, context->sourceBase);
    if (status == OK)
        status = checkRange(context->input, context->sourceBase);
    context->status = status;
}
