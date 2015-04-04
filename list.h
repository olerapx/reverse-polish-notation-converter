#ifndef LIST_H
#define LIST_H

#include"node.h"
#include <stdexcept>
template <typename T>
class List
{
private:
    unsigned int len;
    //for delete and insert operations
    Node<T>* getNodeByValue(const T& value);
    Node<T>* getNodeByIndex(int index);
     void deleteNode (Node<T>* node);
public:
  Node<T> * first;
  Node<T> * last;
  void add(const T &value);
  void insert (const T& value, int index);

  const T &at(int index);
  int indexOf(const T& value);

  void deleteByValue (const T& value);
  void deleteByIndex(int index);

  void clear();

  bool isExists (const T& value);
  inline bool isEmpty(){ return (len==0);}
  inline unsigned int Len(){return len;}
    List();
    ~List();
};

#endif // LIST_H

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

template <typename T>
void List<T>::deleteByValue (const T &value)
{
    if(!isExists(value))return;

  Node<T>* node=getNodeByValue(value);
  if (node==nullptr) return;
  deleteNode(node);
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

template <typename T>
  void List<T>::deleteByIndex(int index)
  {     
      if (len==0 || index<0 ||index >= len) return;
         Node<T>* node=getNodeByIndex(index);
      deleteNode(node);

  }

  template <typename T>
  void List<T>::clear()
  {
      int t_len=len;
    for (int i=0;i<t_len;i++)
    {
     deleteByIndex(0);
    }
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
