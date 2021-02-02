
#define max2 100
#include<iostream>
#include"node.h"
using namespace std;

class Queue
{
public:
  node* data[max2];
  int f,r;
  Queue()
    {
      
      f=r=-1;
    }
  void enqueue(node *temp)
    {
      r++;
      data[r]=temp;
    }
  node* dequeue()
    {
      node *temp;
      f++;
      temp=data[f];
      data[f]=NULL;
      return temp;
      
    }
  int isemp()
    {
      if(f==r)
        return 1;
      return 0;
      
    }
  
  
};


