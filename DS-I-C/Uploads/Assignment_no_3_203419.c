/*
 ============================================================================
 Name        : studdb.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include<stdlib.h>
struct student
{

	int id;
	char name[100],city[100];
	double mks;
};

typedef struct student std;


void accept(std*);
void display(std*);
void dispid(std[],int);
void linsrch(std[],int,int);//Linear Search
void binsrch(std[],int,int);//Binary Search
void bbsort(std[], int);//BubbleSort
void selsort(std[], int);//Selection Sort
void insrtsort(std[], int);//Insertion Sort


int main(void) {
	std s[500];
  int i,n,skey,choice;
	n=0;
  	for(i=0;i<500;i++)//Initialisation to zero
    	{
    		s[i].name[100]="NULL";
    		s[i].city[100]="NULL";
    		s[i].id=0;
    		s[i].mks=0.0;
    	}
  	do//Loop for multiple iterations of the menu
    	{
      	printf("Menu\n0.Exit\n1.Accept details\n2.Display details\n3.Linear Search\n4.Binary Search\n5.Bubble Sort\n6.Selection Sort\n7.Insertion Sort\n");
      	scanf("%d",&choice);
      	switch(choice)
        	{
          	case 0://Exit
            		printf("Thank you\n");
        		return 0;
          	break;

          	case 1://Accept Data
            		printf("Enter the number of students to be added\n");
            		scanf("%d",&n);
            		for(i=0;i<n;i++)
              		{
              			accept(&s[i]);
              		}
            break;

          	case 2://Display the data
            		for(i=0;i<n;i++)
              		{
              			display(&s[i]);
              		}
          	break;

          	case 3://Linear Search
            		printf("Enter the id to be searched\n");
            		scanf("%d",&skey);
            		linsrch(s,n,skey);
          	break;

            case 4://Binary Search
                selsort(s,n);
            		printf("Enter the id to be searched\n");
            		scanf("%d",&skey);
            		binsrch(s,n,skey);
          	break;

            case 5://Bubble Sort
                bbsort(s,n);
            break;

            case 6://Selection Sort
                selsort(s,n);

            break;

            case 7://Insertion Sort
                insrtsort(s,n);

            break;

            default:
          		printf("Error.Please retry");

        	}
	    }while(choice!=0);
	return 0;

}
void dispid(std s[],int n)
{
  for(int t=0;t<n;t++)
  printf("%d\t",s[t].id);
  printf("\n");
}
void insrtsort(std s[],int n)
{

  int i,j ,t;
  std temp;
    for(i=1;i<n;i++)
    {
      j=i-1;
      temp=s[i];
      while(s[j].id>temp.id && j>=0)
        {

          s[j+1]=s[j];
          j--;
        }
      s[j+1]=temp;

          dispid(s,n);


    }
  for(i=0;i<n;i++)
              		{
                			display(&s[i]);
              		}
}


void selsort(std s[],int n)
  {
    int i,j,p;
    std temp,min,sorted[n];
        for(i=0;i<n;i++)
    {
      sorted[i]=s[i];
    }
        for(i=0;i<n-1;i++)
          {
            min=sorted[i];
            p=i;
            for(j=i+1;j<n;j++)
                {

                  if(min.id>sorted[j].id)
                    {
                      min=sorted[j];
                      p=j;
                    }

                }

                      temp=sorted[i];
                      sorted[i]=sorted[p];
                      sorted[p]=temp;
             dispid(sorted,n);
          }
      for(i=0;i<n;i++)
              		{
                			display(&sorted[i]);
              		}
  }


  void bbsort(std s[], int n)
{

  int i,j;
  std temp,sorted[n];
          for(i=0;i<n;i++)
    {
      sorted[i]=s[i];
    }
  for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
        {
          if(sorted[j].id>sorted[j+1].id)
            {
             temp=sorted[j];
             sorted[j]=sorted[j+1];
             sorted[j+1]=temp;
            }

        }
       dispid(sorted,n);
    }
  printf("Database Sorted\n");
  for(i=0;i<n;i++)
              		{
                			display(&sorted[i]);
              		}
}

void binsrch(std s[],int n ,int skey)
  {
    insrtsort(s,n);
  	int low,high,mid;
  	low=0;
  	high=n;
    	while(low<=high)
      	{
      		mid=(low+high)/2;
      		if(s[mid].id==skey)
        		{
        			printf("Student Found\n");
        			display(&s[mid]);
        			break;
        		}
      		if(skey<=s[mid].id)
        		{
        			high=mid-1;
        		}
      		if(skey>=s[mid].id)
        		{
        			low=mid+1;
        		}
      	}
    if(low>high)
      printf("Student not found\n");
  }

void linsrch(std s[], int n,int skey)
  {
	  int i;
	    for(i=0;i<n;i++)
	      {
	        if(s[i].id==skey)
	          {
	          	printf("Student found\n");
	          	display(&s[i]);
	          	break;
	          }
	        else if((i==n-1) && s[i].id!=skey)
	          printf("Student not found");
	      }
  }

void display(std* s)
  {
	  printf("\nStudent Details:\tName: %s \tID: %u \tMarks: %lf\tCity: %s\n",s->name,s->id,s->mks,s->city);
  }

void accept(std* s)
  {
  	printf("Enter the Name\n");
  	scanf("%s",s->name);
  	do{
      printf("Enter the Id\n");
      scanf("%u",&s->id);
      if(s->id<=0)
        printf("Error.Wrong id\n");
    }while(s->id<=0);
  	do{
    printf("Enter the Marks\n");
  	scanf("%lf",&s->mks);
      if(s->mks>100 || s->mks<0)
        printf("Wrong marks entered.Limit crossed\n");
    }while(s->mks>100 || s->mks<0);
  	printf("Enter the City\n");
  	scanf("%s",s->city);


  }
