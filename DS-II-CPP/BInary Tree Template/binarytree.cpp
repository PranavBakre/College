#include<iostream>
#include "stack.h"
#include"node.h"
#include<string.h>

using namespace std;
template<class T>
stack<T> s;
template<class T>
class binary_tree
{
    node<T> *root;

    public:

    binary_tree();
    void createNR();
    node<T>* createR(node<T> *);
    void createR();

    void predisplay(node<T> *  );
    void predisplay();
    void indisplay(node<T> *  );
    void indisplay();
    void postdisplay(node<T> *  );
    void postdisplay();
    void preNRdisplay();
    void inNRdisplay();
    void postNRdisplay();
    void erase(node<T> *);
    void erase();
};
template<class T>
binary_tree<T>::binary_tree():root(NULL)
{

}
template<class T>
void binary_tree<T>::createNR()
    {
        char cont,pos;
        node<T> *temp,*curr;

       do
           {
               if(root==NULL)
                   {
                        root =new node<T>();
                        cout<<"Enter the Data"<<endl;
                        cin>>root->data;
                        root->left=root->right=NULL;
                   }
               else
                    {
                        temp=root;
                        curr=new node<T>();
                        cout<<"Enter the Data"<<endl;
                        cin>>curr->data;
                        curr->left=curr->right=NULL;
                        while(1)
                            {
                                cout<<"Enter the position - L/R"<<endl;
                                cin>>pos;
                                if(pos=='L' || pos=='l')
                                    {

                                        if(temp->left==NULL)
                                            {
                                                temp->left=curr;
                                                break;
                                            }
                                        else
                                            {
                                                temp=temp->left;
                                            }
                                    }
                                else if(pos=='R' || pos=='r')
                                    {

                                        if(temp->right==NULL)
                                            {
                                                temp->right=curr;
                                                break;
                                            }
                                        else
                                            {
                                                cout<<"Entering into next level as node is filled"<<endl;
                                                temp=temp->right;
                                            }
                                    }
                            }
                        }
               cout<<"Do you want to continue? Y/N.\n";
               cin>>cont;
           }while(cont=='Y' || cont=='y');
           cout<<"Tree Created\n";

    }
template<class T>
node<T>* binary_tree<T>::createR(node<T> * root)
    {
        char pos;
        if(root==NULL)
          {
               root=new node<T>();
               cout<<"Enter the data\n";
               cin>>root->data;
               root->left=root->right=NULL;

          }

          {
               cout<<"Add node on left side of "<<root->data<<"? Y/N\n";
               cin>>pos;
               if(pos=='Y' || pos=='y')
                  {
                       root->left=createR(root->left);
                  }
               cout<<"Add node on right side of "<<root->data<<"? Y/N\n";
               cin>>pos;
               if(pos=='Y' || pos=='y')
                   {
                       root->right=createR(root->right);
                  }
          }
         return root;
    }
template<class T>
void binary_tree<T>::predisplay(node<T> * root)
    {
        if(root!=NULL)
            {
                cout<<root->data<<" ";

                predisplay(root->left);


                predisplay(root->right);

            }
    }
    template<class T>
void binary_tree<T>::predisplay()
    {
        predisplay(root);
    }
template<class T>
void binary_tree<T>::indisplay(node <T>* root)
    {
        if(root!=NULL)
            {


                indisplay(root->left);

                cout<<root->data<<" ";
                indisplay(root->right);

            }
    }
template<class T>
void binary_tree<T>::indisplay()
    {
        indisplay(root);
    }
template<class T>
void binary_tree<T>::postdisplay(node<T> * root)
    {
        if(root!=NULL)
            {


                postdisplay(root->left);


                postdisplay(root->right);
                cout<<root->data<<" ";
            }
    }
template<class T>
void binary_tree<T>::postdisplay()
    {
        postdisplay(root);
    }
    template<class T>

void binary_tree<T>::createR()
    {
        root=createR(root);
    }
template<class T>
void binary_tree<T>::preNRdisplay()
    {
        node<T> *temp=root;
        while(1)
        {
        while(temp!=NULL)
        {
        cout<<temp->data<<" ";
        s<T>.push(temp);
        temp=temp->left;


        }
        if(s<T>.isemp())
            break;
        if(!s<T>.isemp())
        {
        temp=s<T>.pop();
        }
        temp=temp->right;
        }
    }
template<class T>
void binary_tree<T>::inNRdisplay()
    {
        node<T> *temp=root;
        while(1)
        {
        while(temp!=NULL)
        {

        s<T>.push(temp);
        temp=temp->left;


        }
        if(s<T>.isemp())
            break;
        if(!s<T>.isemp())
        {
        temp=s<T>.pop();
        }
        cout<<temp->data<<" ";
        temp=temp->right;
        }
    }
template<class T>
void binary_tree<T>::postNRdisplay()
    {
        node<T> *temp;
        temp=root;

        while(1){
        while(temp!=NULL)
            {
                s<T>.push(temp);
                temp=temp->left;

            }

        if(s<T>.data[s<T>.top]->right==NULL)
            {
                temp=s<T>.pop();
                cout<<temp->data<<" ";
            }
        while(!s<T>.isemp() && s<T>.data[s<T>.top]->right==temp)
        {
            temp=s<T>.pop();
            cout<<temp->data<<" ";
        }
        if(s<T>.isemp())
        break;
        temp=s<T>.data[s<T>.top]->right;
    }
    }

template<class T>
void binary_tree<T>::erase(node<T> *root)
    {

        if(root!=NULL)
            {

                cout<<root->data<<" ";
                erase(root->left);
                erase(root->right);
                //strcpy(root->data,"");
               delete(root);
               // root->left=root->right=NULL;



            }
        //    root=NULL;


}
template<class T>
void binary_tree<T>::erase()
{
    erase(root);
   // root=NULL;
}

int main()
{
    int choice;
    binary_tree<string> t;
    /*cout<<"NON RECURSIVE:\n";
    t1.createNR();
    t1.predisplay();
    cout<<"RECURSIVE:\n";
    t2.createR();
    t2.predisplay();
    cout<<"\n";
    t2.indisplay();
    cout<<"\n";
    t2.postdisplay();
    cout<<"\n";*/
    do{
    cout<<"Menu\n1.Create a tree Non recursively\n2.Create a tree recursively\nEnter your choice\n";
    cin>>choice;

    switch(choice)
        {
            case 1:
            cout<<"NON RECURSIVE:\n";
            t.createNR();
            break;

            case 2:
            cout<<"RECURSIVE:\n";
            t.createR();
            break;

            default:
            cout<<"Error.Please retry\n";
        }
    }while(choice!=1 && choice!=2);
    do{
    cout<<"Display \n1.Recursively\n2.Non recursively\n";
    cin>>choice;

    switch(choice)
        {
            case 1:
                cout<<"Preorder:";
                t.predisplay();
                cout<<"\nInorder:";
                t.indisplay();
                cout<<"\nPostorder:";
                t.postdisplay();
                cout<<"\n";
            break;

            case 2:
                cout<<"\nPreorder:";
                t.preNRdisplay();
                cout<<"\nInorder:";
                t.inNRdisplay();
                cout<<"\nPostorder:";
                t.postNRdisplay();
                cout<<"\n";

            break;

            default:
            cout<<"Error.Please Retry\n";

        }
    }while(choice!=1 && choice!=2);
    char choice2;
    cout<<"Delete the tree? Y/N\n";
    cin>>choice2;
    if(choice2=='y' || choice2=='Y')
       {
            t.erase();
            cout<<"Tree deleted\n";

       }
    return 0;
}
