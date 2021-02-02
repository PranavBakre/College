#ifndef NODE
#define NODE
#define maxsize 100
#include<iostream>
using namespace std;
template<class T>
class node
{
  public:
    node *left,*right;
    T data;
    //friend class binary_tree;
   // friend class stack;
    
    node();
};
template<class T>
node<T>::node()
    {
        left=right=NULL;
    
    }
#endif    

