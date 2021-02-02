#include<iostream>
#include<math.h>
using namespace std;


class node  //Node definition
    {
        double coeff;
        double exp;
        node* next;
    
        public:
    
        friend class polynomial;
    };

class polynomial
    {
        node *H;
    
        public:
    
        polynomial()
            {
                H=new node();
                H->next=H;
                H->exp=-1;
            }
        
        int create();
        int display();
        polynomial add( polynomial );
        int eval();
    };



int polynomial::create()    //Create a polynomial CLL
    {
    	node *curr,*temp;
	    curr=H;
	    int i,n;
	    
	    cout<<"Enter the number of repetitions"<<endl;
	    cin>>n;
	    for(i=0;i<n;i++)
	        {
		        temp= new node();
		        cout<<"Enter the coefficient"<<endl;
		        cin>>temp->coeff;
        		cout<<"Enter the exponent"<<endl;
        		cin>>temp->exp;
        		curr->next=temp;
        		temp->next=H;
        		curr=curr->next;


        	}
        return 0;
    }

int polynomial::display() //Display a polynomial CLL
    {
    	node * curr;
    	curr=H->next;
    	while(curr!=H)
    		{
    			cout<<"("<<curr->coeff<<"x^"<<curr->exp<<")";
    			if(curr->next!=H)
    				cout<<"+";
    			else
    				cout<<endl;
    			curr=curr->next;
    
    		}
        return 0;
    }

polynomial polynomial::add(polynomial p2) //Add two polynomials 
    {
        polynomial p3;
        node *c1,*c2,*c3,*temp;
        c1=H->next;
        c2=p2.H->next;
        c3=p3.H;
    
        while(c1->exp != -1 && c2->exp!=-1)//ISSUE CONDITION
            {
    
                temp=new node();
            	if(c1->exp>c2->exp)
		            {
                        temp->exp=c1->exp;
                        temp->coeff=c1->coeff;
        		    	c1=c1->next;
           		    }
            	else if(c1->exp<c2->exp)
            		{
                        temp->exp=c2->exp;
                        temp->coeff=c2->coeff;
            			c2=c2->next;
            		}
            	else
            		{

            			temp->coeff=c1->coeff+c2->coeff;
            			temp->exp=c1->exp;
            			c1=c1->next;
            			c2=c2->next;


            		}
        c3->next=temp;
        temp->next=p3.H;
    	c3=c3->next;
            }
        if(c1==H && c2!=p2.H)
        	{
        		c3->next=c2;
        		while(c2->next!=p2.H)
        			{
        				c2=c2->next;
        			}
        		c2->next=p3.H;
            }
        else if(c2==p2.H && c1!=H)
            {
            	c3->next=c1;
        		while(c1->next!=H)
        			{
        				c1=c1->next;
        			}
        		c1->next=p3.H;
            }
        return p3;
    }

int polynomial::eval()  //Evalualte a polynomial
    {
        node * curr;
        curr=H->next;
        double sum=0,num;
        cout<<"Enter the number"<<endl;
        cin>>num;
        while(curr!=H)
            {
    
                sum=sum + curr->coeff* pow(num,curr->exp);
                curr=curr->next;
            }
        cout<<"Evaluated Value: "<<sum<<endl;
        return 0;
    }


int main()
{
    polynomial p[2],sum;
    int i;

    cout<<"Enter the polynomials"<<endl;
    for(i=0;i<2;i++)    //For loop to accept two polynomials
        {
            cout<<"Polynomial "<<i+1<<": \n";
            p[i].create();
        }
    
    for(i=0;i<2;i++)
        {
            cout<<"Polynomial "<<i+1<<":";
            p[i].display();
        }
    sum=p[0].add(p[1]);
    sum.display();
    sum.eval();
    return 0;
}

