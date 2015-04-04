#ifndef SYMBOLDEFINER_H
#define SYMBOLDEFINER_H

//используется для определения типа символа
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
                                {'|',2}, //ИЛИ
                                {'&',3}, //И
                                {'!',4}, //НЕ
                                {'<',5},{'>',5},
                                {'=',5},{'~',5}, //равно/не равно
                                {'+',6},{'-',6},
                                {'*',7},{'/',7},
                                {'^',8}};

public:
int getType(char s);
int getPriority(char s);
};

#endif // SYMBOLDEFINER_H
