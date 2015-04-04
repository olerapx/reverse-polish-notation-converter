#include "PolishNotationConverter.h"

    std::string PolishNotationConverter::convert(std::string string)
    {
      len=string.length()+1;
      stack= new Stack<char>();
      input=string;
      std::string output;

    for (int i=0;i<len;i++)
    {
        char token=input[i];
        handleToken(token,output,i);
    }
    delete stack;
    return output;

  }


 void PolishNotationConverter::handleToken (char token, std::string &output, const int currIndex)
 {
     SymbolDefiner sdef;
     switch(sdef.getType(token)){
     case SYMBOL_OPERAND:
         output+=token;
         if (sdef.getType(input[currIndex+1])!=SYMBOL_OPERAND) //разграничение чисел пробелами
             output+=' ';
         break;
     case SYMBOL_OPERATION:
         handleOperation(token,output);
         break;
     case SYMBOL_LBRACKET:
         stack->push(token);
          break;
     case SYMBOL_RBRACKET:
         while (sdef.getType(stack->getTos())!=SYMBOL_LBRACKET){
             output+= stack->pop();
         }

         stack->pop();
         break;
     case SYMBOL_ZERO:
         while (!stack->isEmpty()) output+=stack->pop();
         break;
     }

 }

//обработка символа операции
 void PolishNotationConverter::handleOperation (char token, std::string & output)
 {
     SymbolDefiner sdef;
     if(stack->isEmpty())
         stack->push(token);
     else if (sdef.getPriority(token)>sdef.getPriority(stack->getTos()))
          stack->push(token);
    else{
         while (!stack->isEmpty() && sdef.getPriority(stack->getTos())>= sdef.getPriority(token) && sdef.getType(stack->getTos())!=SYMBOL_LBRACKET)
               output+=stack->pop();

         stack->push(token);
    }

 }

