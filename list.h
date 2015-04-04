#ifndef LIST_H
#define LIST_H

#include"node.h"
#include <stdexcept>
template <typename T>
class List
{
private:
    unsigned int len;
    Node<T> * first;
    Node<T> * last;
    //for delete and insert operations
    Node<T>* getNodeByValue(const T& value);
    Node<T>* getNodeByIndex(int index);
     void deleteNode (Node<T>* node);
public:
     List();
     ~List();

  void add(const T &value);
  inline void operator << (const T& value) {add(value);}
  void insert (const T& value, int index);

  const T &at(int index);
  inline const T & operator [] (int index){ return at(index);}
  int indexOf(const T& value);

  void removeValue (const T& value);
  void removeAt(int index);

  void clear();

  bool isExists (const T& value);
  inline bool isEmpty(){ return (len==0);}
  inline unsigned int Len(){return len;}

};



template<typename T>
List<T>::List()
{
    first=nullptr;
    last=nullptr;
    len=0;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::add(const T& value)
{
    Node<T>* node=new Node<T>(value);
    if (first==nullptr) //no elements
    {
        first=node;
        last=node;
    }
    else
    {
        node->prev=last;
        node->prev->next=node;
        last=node;
    }
    len++;

}

 template <typename T>
 void List<T>::insert (const T& value, int index)
 {
   try{
         if (index<0 || index>len)throw std::out_of_range("Incorrect index");

         if (index==len)
         {
             add(value);
             return;
         }

          Node<T> *replaceNode = getNodeByIndex(index);
          Node<T>* node=new Node<T> (value);


          if(index==0)
          {
              node->next=replaceNode;
              node->prev=nullptr;
              replaceNode->prev=node;
              first=node;

          }
          else
          {
              node->next=replaceNode;
              node->prev=replaceNode->prev;
                replaceNode->prev->next=node;
              replaceNode->prev=node;

          }

          if (index==len-1) last=replaceNode;

          len++;
    }
     catch (std::out_of_range)
     {
     }
 }

template <typename T>
bool List<T>::isExists(const T &value)
{
    if(indexOf(value)==-1) return false;
    else return true;
}

template <typename T>
int List<T>::indexOf(const T &value)
{

   int index=-1;
   if(len==0) return index;

   Node<T>* currNode=first;
   index=0;
   while(index!=len){

       if (currNode->value==value)return index;

       index++;
       currNode=currNode->next;
   }
   return -1;

}

template<typename T>
const T& List<T>::at(int index)
{
    try
    {
        if (len==0 || index<0 || index>=len) throw std::out_of_range("Incorrect index");

        Node<T>* currNode=first;
        for(int i=0;i<index;i++)
            currNode=currNode->next;

        return currNode->value;
    }
    catch (std::out_of_range)
    {

    }
}

template <typename T>
void List<T>::removeValue (const T &value)
{
    if(!isExists(value))return;

  Node<T>* node=getNodeByValue(value);
  if (node==nullptr) return;
  deleteNode(node);
}

template <typename T>
void List<T>::removeAt(int index)
  {
      try{
          if (len==0 || index<0 ||index >= len) throw std::out_of_range ("Incorrect index");
          Node<T>* node=getNodeByIndex(index);
          deleteNode(node);
      }
      catch (std::out_of_range)
      {
      }
  }


template <typename T>
void List<T>::clear()
  {
    int t_len=len;
    for (int i=0;i<t_len;i++)
        removeAt(0);
  }


template<typename T>
Node<T>* List<T>::getNodeByValue(const T& value)
 {

     Node<T>* currNode=first;

     for(int i=0;i<len;i++){
              if (currNode->value==value)return currNode;
              currNode=currNode->next;
          }

     return nullptr;
 }


template<typename T>
Node<T>* List<T>::getNodeByIndex(int index)
{
     Node<T>* node=first;
     for (int i=0;i<index;i++)
         node=node->next;
     return node;

}

template <typename T>
void List<T>::deleteNode (Node<T>* node)
   {

    if (node==first &&node==last){
           first=nullptr;
           last=nullptr;
           len--;
           return;
       }

    if (node==first)
       {
           first=node->next;
           node->next->prev=nullptr;
           len--;
           return;
       }

    if(node==last){
         last=node->prev;
         node->prev->next=nullptr;
         len--;
         return;
       }

    node->prev->next=node->next;
    node->next->prev=node->prev;
    len--;
    delete node;

   }

  #endif // LIST_H
