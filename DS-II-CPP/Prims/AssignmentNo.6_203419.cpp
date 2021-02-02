#define MAX 500
#include<iostream>
using namespace std;
class prim
{
int nv,ne;
int am[MAX][MAX];

public:
prim()
{
    int i,j;
    for(i=0;i<MAX;i++)
    {   for(j=0;j<MAX;j++)
        {
        am[i][j]=MAX;
        }

    }
}
void createAM()
{
    int i,v1,v2,cost;

    cout<<"Enter the number of vertices\n";
    cin>>nv;

    cout<<"Enter the number of edges\n";
    cin>>ne;

    for(i=0;i<ne;i++)
    {
        cout<<"Enter the vertices of the edge and the cost\n";
        cin>>v1>>v2>>cost;
        if((v1>-1 && v1<nv && v2>-1 && v2<nv))
        {
        am[v1][v2]=cost;
        am[v2][v1]=am[v1][v2];
        }

    }

}

void display()
{
    int i,j;
    cout<<"Adjacency Matrix:\n";
    for(i=0;i<nv;i++)
    {
        for(j=0;j<nv;j++)
        {
        cout<<am[i][j]<<"\t";

        }
    cout<<endl;
    }
}

int prims(int stv)
{
    int i,j;
    int nearest[nv],r,min,k,mincost;
    mincost=0;

    for(i=0;i<nv;i++)
    {
        if(i!=stv)
            nearest[i]=stv;
    }
    nearest[stv]=-1;
    r=0;

    for(i=0;i<nv;i++)
    {
        min=MAX;
        for(j=0;j<nv;j++)
        {
            if(nearest[j]!=-1 && am[j][nearest[j]]<min)
            {
                k=j;
                min=am[j][nearest[j]];
            }
        }
        if(min!=MAX)
        mincost=mincost+min;
        nearest[k]=-1;


        for(j=0;j<nv;j++)
        {
            if(nearest[j]!=-1 && am[j][nearest[j]]>am[j][k])
                {
                    nearest[j]=k;
                }
        }
    }

    return mincost;
}


};


int main()
{
int stv;
prim p;
p.createAM();
cout<<"Enter the starting vertex number\n";
cin>>stv;
cout<<"Length of the minimum spanning tree : "<<p.prims(stv)<<endl;
p.display();

return 0;
}
