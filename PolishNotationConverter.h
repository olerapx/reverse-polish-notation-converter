#ifndef PolandNotationConverter_H
#define PolandNotationConverter_H
#include "stack.h"
#include "symboldefiner.h"
#include <string>


class PolishNotationConverter
{
    int len;
  Stack<char>* stack;
std::string input;
   void handleToken (char token, std::string &output, const int currIndex);   //обработка символа входящей строки
   void handleOperation (char token, std::string & output); //обработка символа операции

public:

    std::string convert(std::string string);


};

#endif // PolandNotationConverter_H
