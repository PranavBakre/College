#include<iostream>
#include"node.h"
using namespace std;

#define max 10


class stack
{
public:
  int top;
  node* data[max];
  

  stack()
    {
      top=-1;
    }
  void push(node * temp)
    {
      top++;
      data[top]=temp;
      
    }
  node* pop()
    {
      node* temp;
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


