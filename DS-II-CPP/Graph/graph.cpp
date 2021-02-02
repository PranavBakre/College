//============================================================================
// Name        : graph.cpp
// Author      :Pranav Bakre
// Roll No     :203419
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;
#define MAX 1000
class node
{
    string name;
    node *next;

    public:
        node()
            {
                next=NULL;
            }
        friend class graph;
        friend class Queue;
        friend class Stack;
};
// Stack
class Stack
{
    node *data[MAX];
    int top;

    public:

    Stack()
    {
        top=-1;
    }

    void push(node *temp)
    {
        top++;
       data[top]=temp;
    }

    node* pop()
    {
        node* temp;
        temp=data[top];
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
//Stack end
//Queue start


class Queue
{
 node* data[MAX];
  int f,r;

  public:

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
//Queue end


class graph
{
    int n;//Number of users
    node *H[MAX];//Users
    public:

    graph()//Default constructor
    {
        int i;

        n=0;
        for(i=0;i<MAX;i++)
        {
            H[i]=NULL;
        }
    }

    void createAL();//Create adjacency list
    int friendexist(int, node*);//Check if friend is already present
    void graphdisp();//Display the graph
    void listdisp(int );//Display individual users friends

    int getvertexno(node *);//Get the user number
    void bfs();//Breadth first traversal
    //Depth first traversal
    void dfs();
    void dfs(node*,int[],int);//Recursion

    void dfsNR();//Non recursive
};


void graph::createAL()
{
    char choice;
    int i,j,f,fexist,fexist2,ctr;
    node *temp,*ftemp,*friendtrvse,*Htrvse,*t2;
    if(n==0)
    {
    cout<<"Enter the number of users\n";
    cin>>n;
    for(i=0;i<n;i++)
        {
            H[i]=new node();
            cout<<"Enter the name of the user\n";
            cin>>H[i]->name;
            H[i]->next=NULL;
        }
     }
     for(i=0;i<n;i++)
        {

            do{
            cout<<"Enter the friends of "<<H[i]->name<<endl;
            temp=new node();
            cin>>temp->name;
            if(temp->name==H[i]->name)
                {
                    cout<<"Error.User cannot be a friend of himself\n";

                }
            else{
            ctr=0;
            for(j=0;j<n;j++)
            {
            if(temp->name!=H[j]->name)
                ctr++;

            }
            if(ctr==n)
                {
                cout<<"Error.Friend doesnt exist\n";

                }
            else{
            fexist=friendexist(i,temp);
            if(fexist==0)
            {
                temp->next=H[i]->next;
                H[i]->next=temp;
                for(j=0;j<n;j++)
                {
                    if(j!=i)
                    if(H[j]->name==temp->name)
                        {
                        Htrvse=H[j];
                        f=j;
                        break;
                        }
                }
                t2=H[i];
            fexist2=friendexist(f,t2);
            if(fexist2==0)
            {
                ftemp=new node();
                ftemp->name=H[i]->name;
                ftemp->next=Htrvse->next;
                Htrvse->next=ftemp;
                Htrvse=NULL;
            }
            }
            }}
            cout<<"Do you want to add another friend?\n";
            cin>>choice;
            }while(choice=='y'||choice=='Y');
        }


}

int graph::friendexist(int i,node *temp)
{
    node *friendtrvse;
            friendtrvse=H[i]->next;
            while(friendtrvse!=NULL)
            {
                if(friendtrvse->name==temp->name)
                {
                    cout<<"Friend exists\n";
                    delete(temp);
                    return 1;
                }
                else
                friendtrvse=friendtrvse->next;
            }
        return 0;
}

void graph::graphdisp()
{
int i;
cout<<"Graph Display\n";
for(i=0;i<n;i++)
{
listdisp(i);
}

}

void graph::listdisp(int i)
{

node* temp;
temp=H[i]->next;
cout<<H[i]->name<<"\t-";
while(temp!=NULL)
{
    cout<<temp->name;
    temp=temp->next;
    if(temp!=NULL)
        cout<<"->";
    else
        cout<<"\n";
}
cout<<"\n";
}


void graph::bfs()
{
    node *v,*w;
    string name;
    int i,visited[n],vno,c,arrowcount=0;
    cout<<"BFS display\n\n\n";
    graphdisp();

    do{
    cout<<"Enter the start variable\n";
    cin>>name;

    for(i=0;i<=n;i++)
    {
        if(i==n)
            break;
        if(name==H[i]->name)
            break;
    }
    if(i==n)
        {
            cout<<"Error.Name doesnt exist\n\n";

        }
    }while(i==n);
    v=H[i];

   // vno=getvertexno(v);
    if(vno==-1)
        return;

    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    Queue q;
    q.enqueue(v);

    while(!q.isemp())
    {
        v=q.dequeue();
        vno=getvertexno(v);
        visited[vno]=1;
        cout<<v->name;
        arrowcount++;

        if(arrowcount<=n-1)
            cout<<"->";

        w=v->next;
        while(w!=NULL)
        {
            vno=getvertexno(w);
            if(!visited[vno])
                {
                    q.enqueue(H[vno]);
                     visited[vno]=1;
                }
            w=w->next;

        }

    }

}


int graph::getvertexno(node *temp)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(temp->name==H[i]->name)
            return i;

    }
    return -1;
}

void graph::dfs()
{
    int i,visited[MAX],arrowcount=0;
    string name;
    node *v;
    for(i=0;i<n;i++)
        {
            visited[i]=0;
        }
    cout<<"DFS display (Recursive)\n\n\n";

    do{
    cout<<"Enter the vertex name\n";
    cin>>name;
    for(i=0;i<=n;i++)
    {
        if(i==n)
            break;
        if(name==H[i]->name)
            break;
    }
    if(i==n)
        {
            cout<<"Error.Name doesnt exist\n\n";

        }
    }while(i==n);
    v=H[i];
    dfs(v,visited,arrowcount);
}

void graph::dfs(node* v,int visited[],int arrowcount)
{
    int vno;
    node* w;
    vno=getvertexno(v);
    cout<<v->name;
    arrowcount++;
    if(arrowcount<n)
        cout<<"->";


    visited[vno]=1;

        w=v->next;
    while(w!=NULL)
    {
        vno=getvertexno(w);
        if(!visited[vno])
                {
                dfs(H[vno],visited,arrowcount);
                //visited[vno]=1;
                }
    w=w->next;
    }
}

void graph::dfsNR()
{
    int i,visited[MAX],vno,arrowcount=0;
    string name;
    node *v,*w;

    Stack s;

    for(i=0;i<n;i++)
        {
            visited[i]=0;
        }
    cout<<"BFS display(Non Recursive)\n\n\n";
    do{
    cout<<"Enter the vertex name\n";
    cin>>name;
    for(i=0;i<=n;i++)
    {
        if(i==n)
            break;
        if(name==H[i]->name)
            break;
    }
    if(i==n)
        {
            cout<<"Error.Name doesnt exist\n\n";
        }
    }while(i==n);

    v=H[i];
    s.push(v);
    while(!s.isemp())
    {
        v=s.pop();
        vno=getvertexno(v);
        visited[vno]=1;
        w=v->next;
        cout<<v->name;
        arrowcount++;
        if(arrowcount<n)
            cout<<"->";
        while(w!=NULL)
        {
            vno=getvertexno(w);
            if(!visited[vno])
            {
                s.push(H[vno]);
                visited[vno]=1;
            }
            w=w->next;
        }

    }




}


int main()
{
graph G;
G.createAL();
G.graphdisp();

G.bfs();
cout<<endl;

G.dfs();
cout<<endl;

G.dfsNR();
cout<<endl;
return 0;
}
