#include<stdio.h>
#include<stdlib.h>
#define max 5


//Declaration of structure node
struct node
{
  int data;
  struct node *next;
};
typedef struct node node;


int create(node *);
int delete(node *);
void display(node *);
void displayall(node*[]);


int length(node *);
void insertbypos(node *);
int deletebypos(node *);
int sort(node *);
void merge(node *, node *);
int reverse(node *);


int main()
{
  node *Header[max];
  int i,j,yn,choice,position,listnum;
  yn=1;

  for(i=0;i<max;i++)
    {
      Header[i]=(node*)malloc(sizeof(node));
    }

  do
    {
      printf("Menu\n1.Create a list\n2.Display all the lists\n3.Insert an element by position\n4.Delete an element by position\n5.Reverse a list\n6.Sort a list\n7.Merge two lists\n\n\n0.Exit\nEnter your choice\n\n\n");
      scanf("%d",&choice);
      switch(choice)
        {
        case 0:
          printf("Thank you\n");
        return 0;
        case 1:
          i=0;
          while(i<max-1 && Header[i]->next!=NULL )
            {
              i++;
            }
          if(i==max-1 && Header[i]->next!=NULL)
            {
              printf("Error.Maximum number of lists reached. Delete an existing list to continue\n");
              displayall(Header);
              scanf("%d",&i);
              i--;
              delete(Header[i]);
            }
          create(Header[i]);
          display(Header[i]);
        break;
        case 2:
          displayall(Header);
        break;
        case 3:
          displayall(Header);
          do
            {
              printf("Enter the list number\n");
              scanf("%d",&listnum);
              yn=1;
              if(listnum>max)
                {
                  printf("Error.List number too large.Creating a new list at an empty position\n");
                  for(i=0;Header[i]->next!=NULL && i<max-1;i++)
                    {}
                  if(Header[i]->next!=NULL)
                    printf("Error.Maximum number of lists reached.\n");
                  else
                    {
                      insertbypos(Header[i]);
                      display(Header[i]);
                    }
                }
              else
                {
                  listnum--;
                  if(Header[listnum]->next==NULL)
                    {
                      printf("Create a new list?\n1.Yes\n2.No\n");
                      scanf("%d",&yn);
                      if(yn==1)
                        {
                          for(i=0;i<listnum;i++)
                            {
                              if(Header[i]->next==NULL)
                                {
                                  listnum=i;
                                  break;
                                }
                            }
                        }
                    }
                  else
                    {
                      i=listnum;
                    }
               if(yn==1)
                    {
        insertbypos(Header[i]);
        display(Header[i]);

                    }
                }
        }while(yn!=1);

        break;
        case 4:
          displayall(Header);
          printf("Enter the list number\n");
          scanf("%d",&listnum);
          listnum--;
          if(listnum>max-1 )
            printf("Error.List doesn't exist\n");
          else if(Header[listnum]->next==NULL)
            printf("Error.List doesn't exist\n");
          else
            {
              deletebypos(Header[listnum]);
              display(Header[i]);

            }
        break;
        case 5:
          displayall(Header);
          printf("Enter the list number\n");
          scanf("%d",&listnum);
          listnum--;
          if(listnum>max-1 )
            printf("Error.List doesn't exist\n");
          else if(Header[listnum]->next==NULL)
            printf("Error.List doesn't exist\n");
          else
            {
              reverse(Header[listnum]);
              display(Header[i]);

            }
        break;
        case 6:
          displayall(Header);
          printf("Enter the list number\n");
          scanf("%d",&listnum);
          listnum--;
          if(listnum>max-1 )
            printf("Error.List doesn't exist\n");
          else if(Header[listnum]->next==NULL)
            printf("Error.List doesn't exist\n");
          else
            {
              sort(Header[listnum]);
              display(Header[i]);

            }
        break;
        case 7:
          displayall(Header);
          printf("Enter the list numbers\n");
          scanf("%d%d",&i,&j);
          i--;
          j--;
          if((i>max-1 || i<0) && (j>max-1 || j<0))
            {
              printf("Error.Lists do not exist\n");
            }
          else
            {
              if(Header[i]->next==NULL)
                {
                  printf("Error.First List does not exist\n");
                }
              else if(Header[j]->next==NULL)
                {
                  printf("Error.Second List does not exist\n");
                }
              else
                {
                  merge(Header[i],Header[j]);
                }
            }

        break;
        default:
       printf("Error.Wrong choice. Please retty\n");
        }
    }while(choice!=0);
  return 0;
}





int create(node *header)
{
  node * temp,*curr;
  int i,n;
  curr=header;
  printf("Enter the number of elements to be added\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      temp=(node*)malloc(sizeof(node));
      printf("Enter the number\n");
      scanf("%d",&temp->data);
      temp->next=NULL;
      curr->next=temp;
      curr=temp;

    }
  return 1;
}

int delete(node * header)
{
  node *curr, *prevdel;

  prevdel=header->next;
  curr=prevdel->next;
  while(prevdel!=NULL)
    {
      curr=prevdel->next;
      free(prevdel);
      prevdel=curr;
    }
  return 1;
}

void display(node *header)
{
  node * curr;
  curr=header->next;
  printf("List= [");
  while(curr !=NULL)
    {
      printf("%d",curr->data);
      curr=curr->next;
      if(curr!=NULL)
        {
          printf(",");
        }
    }
  printf("]\n");
}

void displayall(node *header[])
{
  int j;
  for(j=0;j<max;j++)
    {
      if(header[j]->next!=NULL)
        {
          printf("%d. ",j+1);
          display(header[j]);

        }
    }
}

int length(node * header)
{
  int i=0;
  node * curr;
  curr=header->next;
  while(curr!=NULL)
    {
      i++;
      curr=curr->next;
    }
  return i;
}
void insertbypos(node *header)
{
  int pos,l;
  printf("Enter the position\n");
  scanf("%d",&pos);
  l=length(header);
  if(pos >l+1)
    {
      printf("Error.Position larger than length of the list\n");
      return ;
    }
  else if(pos<=0)
    {
      printf("Error.Position cannot be negative\n");
      return;
    }
  else
    {
      int i=1;
      node *curr,*temp;
      curr=header;

      while(i<pos)
        {
          curr=curr->next;
          i++;
        }

      temp=(node *)malloc(sizeof(node));
      temp->next=curr->next;
      curr->next=temp;
      printf("Enter the data\n");
      scanf("%d",&temp->data);
    }
  return;

}

int deletebypos(node * header)
{
  int pos,l,i;
  node *curr,*temp;
  curr=header;
  printf("Enter the position\n");
  scanf("%d",&pos);
  l=length(header);
  if(pos>l)
    {
      printf("Error.Position larger than the size of the list\n");
    }
  else
    {
      while(i<pos-1)
        {
          curr=curr->next;
          i++;
        }
      temp=curr->next;
      curr->next=temp->next;
      temp->next=NULL;
      free(temp);
    }
  return 1;
}


int reverse(node *header)
{
  node * prev,*curr,*temp;
  prev=NULL;
  curr=header->next;
  while(curr!=NULL)
    {
      temp=curr->next;
      curr->next=prev;
      prev=curr;
      curr=temp;
    }
  header->next=prev;
  return 1;
}

int sort(node * header)
{
  int l,i,j;
  node *curr,*prev,*temp;
  l=length(header);
    for(i=0;i<l;i++)
      {
  prev =header;
  curr=header->next;
  for(j=0;j<l-i-1;j++)
          {
              temp=curr->next;
            if(curr->data>temp->data)
              {

                prev->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                prev=temp;

              }
            else
              {
                prev=curr;
                curr=curr->next;
              }
          }
      }
  return 1;
}


void merge(node * header,node * header2)
{
  int flag;
  node *c1,*c2,*temp;
  sort(header);
  sort(header2);
  c1=header->next;
  c2=header2->next;
  if(c1->data<c2->data)
    {
      flag=1;
      temp=header;

    }
  else
    {
      flag=0;
      temp=header2;
    }
  while(c1!=NULL && c2!=NULL)
    {
      if(c1->data<c2->data)
        {
          temp->next=c1;
          temp=c1;
          c1=c1->next;
        }
      else
        {
          temp->next=c2;
          temp=c2;
          c2=c2->next;
        }
    }
  if(c1!=NULL)
    {
      temp->next=c1;
    }
  else
    {
      temp->next=c2;
    }
  if(flag==1)
    {
      display (header);
    }
  else
    {
      display(header2);
    }
}
