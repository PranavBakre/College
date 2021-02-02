#include<iostream>
using namespace std;
class heap{
int n;
int heaparray[100];


public:
    void createheap()
    {
    int i=1,num,minormax;
    char choice;
    cout<<"Max heap (1) or Min heap (0)?\n";
    cin>>minormax;
    cout<<minormax;


    do{
        cout<<"Enter the student marks\n";
        cin>>num;
        heaparray[i]=num;
        heapify(minormax,i);
        i++;

        cout<<"Do you want to continue\n";
        cin>>choice;
    }while(choice=='y'|| choice=='Y');
    n=i;
    }
    void heapify(int minormax,int i)
    {
        int elem;
        elem=heaparray[i];

        if(minormax==1)
        {
        while(i>1 && elem>heaparray[i/2])
        {
            heaparray[i]=heaparray[i/2];
            i=i/2;

        }
        heaparray[i]=elem;
        }
        else
        {
        while(i>1 && elem<heaparray[i/2])
        {
            heaparray[i]=heaparray[i/2];
            i=i/2;

        }            heaparray[i]=elem;
        }
    }

    void display()
    {
    int i;
    cout<<"Heap:";
    for(i=1;i<n;i++)
    {

        cout<<heaparray[i]<<"\t";

    }

    cout<<"\n";
    }
};


int main()
{
heap h;
char choice;
do{
h.createheap();
h.display();
cout<<"Do you want to retry\n";
cin>>choice;
}while(choice=='y' || choice=='Y');

}
