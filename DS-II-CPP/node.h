#ifndef NODE
#define NODE
#define maxsize 100
#include<iostream>
using namespace std;

class node
{
  public:
    node *left,*right;
    string data;
    //friend class binary_tree;
   // friend class stack;
    
    node();
};

node::node()
    {
        left=right=NULL;
    
    }
#endif    

