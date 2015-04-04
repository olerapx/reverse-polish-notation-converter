#ifndef SYMBOLDEFINER_H
#define SYMBOLDEFINER_H

//for symbol type and priority definition
enum{
    SYMBOL_LBRACKET,
    SYMBOL_RBRACKET,
    SYMBOL_OPERAND,
    SYMBOL_OPERATION,
    SYMBOL_OTHER,
    SYMBOL_ZERO
};

class SymbolDefiner
{
private:
   const static int operationsNumber=14;
   struct Operation{
    char symb;
    int priority;
}operations[operationsNumber]= {{'(',0}, {')',1},
                                {'|',2}, //OR
                                {'&',3}, //AND
                                {'!',4}, //NOT
                                {'<',5},{'>',5},
                                {'=',5},{'~',5}, //equal/not equal
                                {'+',6},{'-',6},
                                {'*',7},{'/',7},
                                {'^',8}};//power

public:
int getType(char s);
int getPriority(char s);
};

#endif // SYMBOLDEFINER_H
