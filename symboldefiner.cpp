#include "symboldefiner.h"
#include <ctype.h>

int SymbolDefiner::getType(char s){

    if (s==operations[0].symb) return SYMBOL_LBRACKET;
    if (s==operations[1].symb) return SYMBOL_RBRACKET;

    for (int i=2;i<operationsNumber;i++)
        if (s==operations[i].symb) return SYMBOL_OPERATION;


    if (isdigit(s)|| isalpha(s) || s=='.') return SYMBOL_OPERAND;
    if (s=='\0') return SYMBOL_ZERO;

    return SYMBOL_OTHER;
}

int SymbolDefiner::getPriority(char s){
    for (int i=0;i<operationsNumber;i++)
        if (s==operations[i].symb){
            return operations[i].priority;
        }
    return -1;
}
