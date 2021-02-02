#include<iostream>
using namespace std;
#define max 10

#define maxsize 100

class node
{

    node *left,*right;
    char data[maxsize];
  public:
    friend class binary_tree;
    friend class stack;

    node();
};

node::node()
    {
        left=right=NULL;

    }


class stack
{

  int top;
  node* data[max];
public:
    friend class binary_tree;
  stack()
    {
      top=-1;
    }
  void push(node * temp)
    {
      top++;
      data[top]=temp;

    }
  node* pop()
    {
      node* temp;
      temp=data[top];
      data[top]=NULL;
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


stack s;


class binary_tree
{
    node *root;

    public:

    binary_tree();
    void createNR();
    node* createR(node *);
    void createR();

    void predisplay(node *  );
    void predisplay();
    void indisplay(node *  );
    void indisplay();
    void postdisplay(node *  );
    void postdisplay();
    void preNRdisplay();
    void inNRdisplay();
    void postNRdisplay();
    void erase(node *);
    void erase();
};
//Binary tree functions
binary_tree::binary_tree()
    {

        root=NULL;
    }

void binary_tree::createNR()//Create binary th=ree non recursively
    {
        char cont,pos;
        node *temp,*curr;

       do
           {
               if(root==NULL)
                   {
                        root =new node();
                        cout<<"Enter the Data"<<endl;
                        cin>>root->data;
                        root->left=root->right=NULL;
                   }
               else
                    {
                        temp=root;
                        curr=new node();
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

node* binary_tree::createR(node * root) // Create  binary tree recursively
    {
        char pos;
        if(root==NULL)
          {
               root=new node();
               cout<<"Enter the data\n";
               cin>>root->data;
               root->left=root->right=NULL;
               root=createR(root);
          }
        else
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
// Non recursive display functions
// Pre order display functions
void binary_tree::predisplay(node * root)
    {
        if(root!=NULL)
            {
                cout<<root->data<<" ";

                predisplay(root->left);


                predisplay(root->right);

            }
    }
void binary_tree::predisplay()
    {
        predisplay(root);
    }
//In order display functions
void binary_tree::indisplay(node * root)
    {
        if(root!=NULL)
            {


                indisplay(root->left);

                cout<<root->data<<" ";
                indisplay(root->right);

            }
    }

void binary_tree::indisplay()
    {
        indisplay(root);
    }
// Postorder display functions
void binary_tree::postdisplay(node * root)
    {
        if(root!=NULL)
            {


                postdisplay(root->left);


                postdisplay(root->right);
                cout<<root->data<<" ";
            }
    }

void binary_tree::postdisplay()
    {
        postdisplay(root);
    }

void binary_tree::createR()
    {
        root=createR(root);
    }
//Non recursive display functions
//Pre order display functions
void binary_tree::preNRdisplay()
    {
        node *temp=root;
        while(1)
        {
        while(temp!=NULL)
        {
        cout<<temp->data<<" ";
        s.push(temp);
        temp=temp->left;


        }
        if(s.isemp())
            break;
        if(!s.isemp())
        {
        temp=s.pop();
        }
        temp=temp->right;
        }
    }
//Inorder display function non-recursive
void binary_tree::inNRdisplay()
    {
        node *temp=root;
        while(1)
        {
        while(temp!=NULL)
        {

        s.push(temp);
        temp=temp->left;


        }
        if(s.isemp())
            break;
        if(!s.isemp())
        {
        temp=s.pop();
        }
        cout<<temp->data<<" ";
        temp=temp->right;
        }
    }
    //Post order display function non recursive
void binary_tree::postNRdisplay()
    {
        node *temp;
        temp=root;

        while(1){
        while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;

            }

        if(s.data[s.top]->right==NULL)
            {
                temp=s.pop();
                cout<<temp->data<<" ";
            }
        while(!s.isemp() && s.data[s.top]->right==temp)
        {
            temp=s.pop();
            cout<<temp->data<<" ";
        }
        if(s.isemp())
        break;
        temp=s.data[s.top]->right;
    }
    }

    //Function definition erase function
void binary_tree::erase(node *root)
    {

        if(root!=NULL)
            {

                cout<<root->data<<" ";
                erase(root->left);
                erase(root->right);
             //   delete(root);
                root->left=root->right=NULL;

                root=NULL;

            }


}
void binary_tree::erase()
{
    erase(root);
}
int main()
{
    int choice;
    binary_tree t;

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
            t.predisplay();
       }
    return 0;
}
