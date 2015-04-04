#include "symboldefiner.h"
#include <ctype.h>

int SymbolDefiner::getType(char s){

    for (int i=0;i<operationsNumber;i++)
        if (s==operations[i].symb){
            if (i==0) return SYMBOL_LBRACKET;
          else  if (i==1) return SYMBOL_RBRACKET;
          else  return SYMBOL_OPERATION;

        }

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
