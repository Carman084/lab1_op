#include "logic.h"

void makeStrUpper(AppContext* context){
    char* input = context->input;
    int len = strlen(input);
    for (int i = 0; i < len; i++){
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= DIFFERENCE_ASCII;
    }
}

//конвертация в десятичную систему счисления
unsigned convertToDecimal(char* input, Base base){
    unsigned result = 0;
    int typeNumber = (*input == '-')? 1 : 0;
    int digit, len = strlen(input);
    for (int i = typeNumber; i < len; i++){
        digit = isdigit(input[i]) ? input[i] - '0' : input[i] - 'A' + HEX_OFFSET;
        result = result * base + digit;
    }
    if (typeNumber)
        result = ~(result) + 1;
    return result;
}

void swap(char* s1, char* s2){
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void reverseStr(char* output, int len){
    for (int i = 0; i < len / HALVING; i++)
        swap(output + i, output + len - i - 1);
}

//конвертация из десятичной системы счисления в любую
char* convertFromDecimal(unsigned value, Base base){ //
    int len = 0, typeNumber = 0;
    char* output = allocStr(LEN);
    if (base == BASE_DEC){
        int signedValue = (int)value;
        typeNumber = (signedValue < 0) ? 1 : 0;
        value = typeNumber ? -(unsigned)signedValue : value;
    }
    if (value == 0)
        output[len++] = '0';
    while (value > 0 && output){
        int digit = value % base;
        char c = (digit < HEX_OFFSET) ? ('0' + digit) : ('A' + digit - HEX_OFFSET);
        output[len++] = c;
        value /= base;
    }
    if (output){
        if (typeNumber)
            len++;
        if (typeNumber)
            output[len - 1] = '-';
        reverseStr(output, len);
        output[len] = 0;
    }
    return output;
}

void convertInput(AppContext* context){
    freeStr(context -> output);
    if (context -> sourceBase == context -> lastBase){
        context->output = allocStr(strlen(context->input));
        if (context->output)
            strcpy(context->output, context->input);
        else
            context->status = ERROR_MEMORY;
    }
    else{
        unsigned value = convertToDecimal(context->input, context->sourceBase);
        if (context ->status == OK){
            context -> output = convertFromDecimal(value, context->lastBase);
            if (!context->output)
                context->status = ERROR_MEMORY;
        }
    }
}

void freeContext(AppContext* context) {
    freeStr(context->input);
    freeStr(context->output);
}

void updateInput(AppContext* context, AppParams* params) {
    freeStr(context->input);
    context->input = allocStr(strlen(params->input));
    if (context->input){
        strcpy(context->input, params->input);
        makeStrUpper(context);
    }
    else
        context->status = ERROR_MEMORY;
}

void updateSourceBase(AppContext* context, AppParams* params){
    context->sourceBase = params->sourceBase;
}

void updateLastBase(AppContext* context, AppParams* params){
    context->lastBase = params->lastBase;
}

void initContext(AppContext* context){
    context->input = NULL;
    context->output = NULL;
    context->sourceBase = BASE_BIN;
    context->lastBase = BASE_DEC;
    context->status = OK;
}
