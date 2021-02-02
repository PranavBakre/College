#ifndef NODE
#define NODE
#include<iostream>
using namespace std;
class node
{
public:

string data;
node *left,*right;
bool lbit,rbit;

node()
{
left=right=NULL;
lbit=rbit=1;

}

};
#endif
