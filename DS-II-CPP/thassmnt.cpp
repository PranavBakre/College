#include<iostream>
#include<iterator>
#include<stack>
using namespace std;

void display(stack<int> s)
{
    int a;
    stack<int> temp;
    while(!s.empty())
    {


        cout<<s.top()<<endl;
        temp.push(s.top());
        s.pop();

    }



}

int main()
{
stack<int> s;


int a=5,b=6,c=78;
cout<<"PUSHING:"<<a<<","<<b<<","<<c<<endl;
s.push(a);

s.push(b);
s.push(c);
cout<<"Stack:\n";
display(s);

a=s.top();
cout<<"Top Value: "<<a<<endl;
cout<<"Popping top value\n";
s.pop();
cout<<"Stack:\n";
display(s);
return 0;
}
