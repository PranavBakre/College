
#include<iostream>
using namespace std;
#include"node.hpp"

class TBT
{
node *root,*head;
public:
    TBT();
    void create();
    void preorder();
    node* inordersucc(node *);
    void inordertrvse();

};
TBT::TBT()
    {
        head=NULL;
        root=NULL;
    }
void TBT::create()
{
    node *temp,*curr;
    char choice;
    if(root==NULL)
    {
        head=new node();
        root=new node();
        cout<<"Enter the root data\n";
        cin>>root->data;
        root->left=head;
        root->lbit=1;
        root->right=head;
        root->rbit=1;
        head->left=root;
        head->lbit=0;
        head->right=head;
        head->rbit=0;
    }

         do
            {
                temp=root;
                curr=new node();
                cout<<"Enter the data\n";
                cin>>curr->data;
                while(1)
                {
                    cout<<"Where to add the node? L/R\n";
                    cin>>choice;
                    if(choice=='L' || choice=='l')
                    {
                        if(temp->lbit==1)
                            {
                                temp->lbit=0;
                                curr->left=temp->left;
                                temp->left=curr;
                                curr->right=temp;
                                break;
                            }
                        else
                            temp=temp->left;
                    }
                    else if(choice=='r'|| choice=='R')
                    {
                        if(temp->rbit==1)
                            {
                                temp->rbit=0;
                                curr->right=temp->right;
                                temp->right=curr;
                                curr->left=temp;
                                break;
                            }
                        else
                            temp=temp->right;
                    }

                }
                cout<<"Do you want to add another node? Y/N\n";
                cin>>choice;
            }while(choice=='Y' || choice=='y');

}



void TBT::preorder()
    {
        node *temp;
        temp=head->left;
        while(temp!=head)
        {
            cout<<temp->data<<" ";
            while(temp->lbit!=1)
            {
                temp=temp->left;
                cout<<temp->data<<" ";

            }
            while(temp->rbit==1)
            {
                temp=temp->right;
            }
            if(temp->rbit==0)
            temp=temp->right;

        }
    }

node* TBT::inordersucc(node * temp)
{
    node *p;
    p=temp->right;
    if(temp->rbit==0)
        {
            while(p->lbit==0)
                {
                    p=p->left;
                }
        }
    return p;
}

void TBT::inordertrvse()
{
    node* temp=head;//->left;


    while(1)
    {
    temp=inordersucc(temp);
    if(temp==head)
        break;
    else
    cout<<temp->data<<" ";
    }
}

    int main()
    {
        TBT t1;
        cout<<"1";
        t1.create();

        cout<<"Preorder display\n";

        t1.preorder();

        cout<<"\nInorder display\n";

        t1.inordertrvse();
        return 0;
    }

