#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "list.h"
template <typename T>
class Stack
{
private:
    int _tos;
    List<T> _stack;

public:
 void push(T element);
 T pop();
 T getTos();
 Stack();
 ~Stack();
bool isEmpty();

};


#endif // STACK_H

template<typename T>
Stack<T>::Stack(){
   _tos=-1;

}

template<typename T>
Stack<T>::~Stack<T>(){

}

template<typename T>
void Stack<T>::push( T element){
      _stack.add(element);
      _tos++;
}


template <typename T>
T Stack<T>::pop(){
    T val= _stack.at(_tos);
     _stack.deleteByIndex(_tos--);
    return val;
}

template <typename T>
bool Stack<T>::isEmpty(){
 return _stack.isEmpty();
}

template <typename T>
T Stack<T>::getTos(){
    if (_tos>=0)
        return  _stack.at(_tos);


}
