#include<iostream>
#define MAX 10
using namespace std;

class student
{
    int roll_no;
    string name;
    int marks;

    public:
        student()
        {
            roll_no=-1;
            name="";
            marks=0;

        }
        void input()
        {
            cout<<"Enter the Roll Number of the student\n";
            cin>>roll_no;
            cout<<"Enter the Name  of the student\n";
            cin>>name;

            cout<<"Enter the Marks of the student\n";
            cin>>marks;

        }

        void display()
        {
            cout<<"Roll No\t Name \t Marks\n";
            cout<<roll_no<<"\t"<<name<<"\t"<<marks<<endl;
        }

        int getrollno()
        {
            return roll_no;
        }

};
class hashtable{
    student hashtables[MAX];

    public:



        void createHASH_NR()
        {
            student s;
            int srollno,roll_repeat,location;
            char choice;

            do
            {
            cout<<"Enter the student record\n";
            s.input();
            while(I_exist(s)==1)
            {
                cout<<"Error. Roll nuimber present in entry\n.Please retry\n";
                s.input();
            }

            location=srollno%MAX;
            while(!I_exist(s))
            {
            if(hashtables[location].getrollno()==-1)
                hashtables[location]=s;
            else
            {
                location++;
            }
            }
            cout<<"Do you want to add another entry\n";
            cin>>choice;
            }while(choice=='y' || choice=='Y');
        }

        void create_HASH_R()
        {
            student s;
            int srollno,locreplace,location,flag;
            char choice;
            flag=1;
            do
            {
            cout<<"Enter the student record\n";
            s.input();

            while(I_exist(s)==1)
            {
                cout<<"Error. Roll nuimber present in entry\n.Please retry\n";
                s.input();
            }
            srollno=s.getrollno();
            location=srollno%MAX;

            while(I_exist(s)==0)
            {

            if(hashtables[location].getrollno()==-1)
                hashtables[location]=s;
            else
            {

                if((hashtables[location].getrollno())%MAX!=location)
                {
                    student temp;
                    temp=hashtables[location];
                    hashtables[location]=s;
                    for(int i=location+1;i<MAX;i=(i+1)%MAX)
                    {
                        if(hashtables[i].getrollno()==-1)
                        {
                            hashtables[i]=temp;
                            flag=0;
                            break;

                        }
                        flag=1;
                    }
                    if(flag==1)
                    {
                        cout<<"Error.Hash table full.Exiting\n";
                        return;
                    }
                }
                else
                {
                    location++;
                }
            }
            }
            cout<<"Do you want to add another entry\n";
            cin>>choice;
            }while(choice=='y' || choice=='Y');


        }


        int I_exist(student s)
        {
            int srollno=s.getrollno();
            for(int i=0;i<MAX;i++)
            {
                if(srollno==hashtables[i].getrollno())
                {
                    return 1;
                }
            }
            return 0;
        }
        void display()
        {
            int i;
            for(i=0;i<MAX;i++)
            {
                hashtables[i].display();
            }

        }
};


int main()
{

hashtable h;
int choice;
cout<<"Create with \n1.Linear Probing With Replacement\n2.Linear Probing Without Replacement\n";
cin>>choice;


switch(choice)
{
case 1:
h.create_HASH_R();
break;
case 2:
h.createHASH_NR();
break;
default:
cout<<"Error.Please retry\n";
}
cout<<"HASH TABLE\n";
h.display();
return 0;
}
