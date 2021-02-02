#include<iostream>
#include"node.h"
using namespace std;
template<class T>
#define max 10


class stack
{
public:
  int top;
  node<T>* data[max];
  

  stack()
    {
      top=-1;
    }
  void push(node<T> * temp)
    {
      top++;
      data[top]=temp;
      
    }
  node<T>* pop()
    {
      node<T>* temp;
      temp=data[top];
      data[top]=NULL;
      top--;
      return temp;
    }
  int isemp()
    {
      if(top==-1)
        return 1;
      return 0;
    }
};


