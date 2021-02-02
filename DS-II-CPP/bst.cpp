#include<iostream>
#include"node.h"
#include"stack.h" 
#include"queue.h"
stack s;
Queue q;
class bst
{
node *root;
public:

    bst();
    void create();
    node* createR(node* =NULL,node* =NULL);
    void createNR();
    void predisplay();
    void predisplay(node *);
    void indisplay();
    void indisplay(node *);
    void postdisplay();
    void postdisplay(node*);

    void preNRdisplay();
    void inNRdisplay();
    void postNRdisplay();
    void bfs();
    int height(node*);
    int height();
    node** search();
    node** search(node*, string);
    void delnode();
    node* copytreeR();
    void copytreeR(bst);
    node* copytreeR(node*);

    void copytreeNR(bst);
    node* copytreeNR();

    void mirrorR();
    void mirrorR(node*);
    void mirrorNR();
    void lfnode()
    {
node *temp=root;
while(1){
while(temp!=NULL)
    {

        s.push(temp);
        if(temp->left==NULL && temp->right==NULL)
        cout<<temp->data<<" ";
        temp=temp->left;

    }
        if(s.isemp())
    {
        break;
    }
    if(!s.isemp())
    {
        temp=s.pop();
       temp=temp->right;
    }


    }

}

    /*
    mirror

    */


};
bst::bst()
{
    root=NULL;
}

void bst::create()
{
           char ch;
    do
    {
        root=createR(root);

        cout<<"Create a node?\n";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}
node* bst::createR(node *root,node *temp)
{
if(root==NULL)
    {
        root=new node();
        cout<<"Enter the data\n";
        cin>>root->data;
        root->left=root->right=NULL;
        createR(root);
    }
    else
    {

        if(temp==NULL)
            {
                temp= new node();
                temp->left=temp->right=NULL;
                cout<<"Enter the node value\n";
                cin>>temp->data;
            }

        if(temp->data==root->data)
            {
                cout<<"Error.Data exists\n";
            }
        else
            {
                if(temp->data>root->data)
                    {
                        if(root->right==NULL)
                            root->right=temp;
                        else
                            {
                            createR(root->right,temp);
                            }
                    }
                else if(temp->data<root->data)
                    {
                        if(root->left==NULL)
                            root->left=temp;
                        else
                            {
                                createR(root->left,temp);
                            }
                    }
             }
        }
    return root;
}
void bst::createNR()
{
    int flag=0;
    char choice;
    node *curr,*temp;
    do
    {
    if(root==NULL)
    {
        root=new node();
        cout<<"Enter the root data\n";
        cin>>root->data;
        root->left=root->right=NULL;
    }
    else
    {
        flag=0;
        curr=root;
        temp=new node();
                    cout<<"Enter the data\n";
            cin>>temp->data;
            temp->left=temp->right=NULL;
        while(flag==0)
        {

            if(curr->data>temp->data)
            {
                if(curr->left==NULL)
                {
                    curr->left=temp;
                    flag=1;
                }
                else
                {
                    curr=curr->left;
                }

            }
            else if(curr->data<temp->data)
            {
                if(curr->right==NULL)
                {
                    curr->right=temp;
                    flag=1;
                }
                else
                {
                    curr=curr->right;

                }
            }
            else
            {
                cout<<"Error.Duplicate key\n";
                delete(temp);
                flag=1;
            }
        }
    }
    cout<<"Do you want to add a node\n";
    cin>>choice;
    }while(choice=='y' || choice=='Y');
}
void bst::predisplay(node * root)
    {
        if(root!=NULL)
            {
                cout<<root->data<<" ";

                predisplay(root->left);


                predisplay(root->right);

            }
    }

void bst::predisplay()
    {
        predisplay(root);
    }

void bst::indisplay()
{
    indisplay(root);
}

void bst::indisplay(node *root)
{
    if(root!=NULL)
    {
        indisplay(root->left);
        cout<<root->data<<" ";
        indisplay(root->right);
    }
}

void bst::postdisplay()
{
    postdisplay(root);
}
void bst::postdisplay(node* root)
{   if(root!=NULL)
    {
        postdisplay(root->left);
        postdisplay(root->right);
        cout<<root->data<<" ";
    }
}

void bst::preNRdisplay()
{
node *temp=root;
while(1){
while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        s.push(temp);
        temp=temp->left;
    }
        if(s.isemp())
    {
        break;
    }
    if(!s.isemp())
    {
        temp=s.pop();
       temp=temp->right;
    }


    }

}

void bst::inNRdisplay()
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
            cout<<temp->data<<" ";
            temp=temp->right;
        }


    }
}

void bst::postNRdisplay()
{
node* temp=root;
if(temp==NULL)
return;
while(1)
    {
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


void bst::bfs()
{
    node *temp=root;
    q.enqueue(temp);
    while(!q.isemp())
    {
        temp=q.dequeue();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        q.enqueue(temp->left);
        if(temp->right!=NULL)
        q.enqueue(temp->right);
    }
}
int bst::height()
{
    int h=height(root);
    cout<<h<<"\n";
	return 0;
}

int bst::height(node *root)
{
    int h1,h2,h;
    if(root==NULL)
        return 0;
    h1=height(root->left);
    h2=height(root->right);
    return h1>h2?++h1:++h2;

}
node** bst::search()
{
node **srch;
string key;
cout<<"\nEnter the key\n";
cin>>key;
srch=search(root,key);
if(srch!=NULL)
    cout<<srch[0]->data<<" "<<srch[1]->data<<endl;
return srch;
}

node** bst::search(node *root,string key)
{
static node *rtn[2];
node *temp,*parent;
temp=root;
parent=NULL;
while(temp!=NULL)
{
    if(temp->data==key)
    {
        rtn[0]=temp;
        if(parent!=NULL)
            rtn[1]=parent;
        else
            rtn[1]=root;
        cout<<rtn[0]->data<<" "<<rtn[1]->data<<endl;
        return rtn;
    }
    else if(temp->data > key)
    {
        parent=temp;
        temp=temp->left;
    }
    else
    {
        parent=temp;
        temp=temp->right;
    }
}
return NULL;
}

void bst::delnode()
{
    node **searchnode;
    node *curr,*temp,*parent,*trvse;
    searchnode=search();
    curr=searchnode[0];
    parent=searchnode[1];
    if(curr!=root)
    {
        if(curr->left==NULL && curr->right==NULL)
        {
            if(parent->left==curr)
                parent->left=NULL;
            else if(parent->right==curr)
                parent->right=NULL;
            delete(curr);

        }
        else if(curr->left==NULL && curr->right!=NULL)
        {
            if(parent->left==curr)
                parent->left=curr->right;
            else if(parent->right==curr)
                parent->right=curr->right;
            curr->left=NULL;
            curr->right=NULL;
            delete(curr);
        }
        else if(curr->left!=NULL & curr->right==NULL)
        {
            if(parent->left==curr)
                parent->left=curr->left;
            else if(parent->right==curr)
                parent->right=curr->left;
            curr->left=NULL;
            curr->right=NULL;
            delete(curr);
        }
        else
        {
            temp=curr->left;

            trvse=curr->right;
            while(trvse->left!=NULL)
            {
                trvse=trvse->left;
            }
            trvse->left=temp;
            if(curr==parent->right)
            {
                parent->right=curr->right;
            }
            else
                parent->left=curr->right;

            curr->left=NULL;
            curr->right=NULL;
            delete(curr);

        }
    }
    else
    {
        if(curr->left!=NULL && curr->right==NULL)
        {
            root=root->left;
            curr->left=NULL;
            delete(curr);
        }
        else if(curr->left==NULL && curr->right!=NULL)
        {
            root=root->right;
            curr->right=NULL;
            delete(curr);
        }
        else if(curr->left==NULL && curr->right==NULL)
        {
            delete(root);
        }
        else
        {
                    temp=root->left;
            root=root->right;

            trvse=curr->right;
            while(trvse->left!=NULL)
            {
                trvse=trvse->left;
            }
            trvse->left=temp;
            delete(curr);
        }
    }

}

void bst::copytreeR(bst t)
{
    root=t.copytreeR();
}
node* bst::copytreeR()
{
    node* root2=copytreeR(root);
    return root2;
}
node* bst::copytreeR(node *root)
{
  node* temp=NULL;
  if(root!=NULL)
  {
    temp=new node();
    temp->data=root->data;
    temp->left=copytreeR(root->left);
    temp->right=copytreeR(root->right);

  }
  return temp;
}

void bst::copytreeNR(bst t)
{
    root=t.copytreeNR();
}
node* bst::copytreeNR()
{
    node *temp1,*temp2,*newroot;
    stack s2;
    temp1=root;
    temp2=new node();
    newroot=temp2;
    temp2->data=temp1->data;
    while(1)
    {
        while(temp1!=NULL)
        {
            if(temp1->left!=NULL)
            {
                temp2->left=new node();
                temp2->left->data=temp1->left->data;

            }
            if(temp1->right!=NULL)
            {
                temp2->right=new node();
                temp2->right->data=temp1->right->data;


            }
            s.push(temp1);
            s2.push(temp2);
            temp1=temp1->left;
            temp2=temp2->left;

    }
    if(s.isemp())
        break;

    if(!s.isemp())
        {
            temp1=s.pop();
            temp2=s2.pop();
            temp1=temp1->right;
            temp2=temp2->right;
        }
    }
   return newroot;
}

void bst::mirrorR()
{
    mirrorR(root);
}

void bst::mirrorR(node *root)
{

    node* temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    if(root->left!=NULL)
        mirrorR(root->left);
    if(root->right!=NULL)
        mirrorR(root->right);
}
void bst::mirrorNR()
{
    node *temp,*swapper;
    q.enqueue(root);
    while(!q.isemp())
    {
        temp=q.dequeue();
        swapper=temp->right;
        temp->right=temp->left;
        temp->left=swapper;
        if(temp->left!=NULL)
            q.enqueue(temp->left);
        if(temp->right!=NULL)
            q.enqueue(temp->right);
    }


}
int main()
{
bst t1,t2;
string key;
t1.createNR();
t1.predisplay();

cout<<"\n";
t1.height();
t2.copytreeNR(t1);
t1.predisplay();

cout<<"\n";
t1.lfnode();
cout<<"\n";

t1.search();
t1.delnode();
//cout<<"\n";

t1.preNRdisplay();
t1.mirrorNR();
cout<<"\n";
t1.predisplay();
//t1.postNRdisplay();
//t1.bfs();
return 0;
}
