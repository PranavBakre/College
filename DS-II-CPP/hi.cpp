#include<iostream>
using namespace std;

class hi{
//int a;
public:
int fi();
};

int hi::fi()
{
int b;
static int a=0;
cin>>b;
if(b==1){
a++;
}
if(b==0)
{
    a=0;
}
return a;
}

int main()
{
hi hi1,hii;
cout<<hi1.fi();
cout<<hii.fi();
return 0;
}

