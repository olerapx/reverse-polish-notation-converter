#ifndef PolishNotationConverter_H
#define PolishNotationConverter_H
#include "stack.h"
#include "symboldefiner.h"
#include <string>


class PolishNotationConverter
{
    int len;
  Stack<char>* stack;
std::string input;
    //handle of characters of input string
   void handleToken (char token, std::string &output, const int currIndex);

   //will be called if character is operation
   void handleOperation (char token, std::string & output);

public:

    std::string convert(std::string string);


};

#endif // PolandNotationConverter_H
