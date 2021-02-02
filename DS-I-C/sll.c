#include<stdio.h>
#include<stdlib.h>
#define max 5
struct sllnode
{
  int data;
  struct sllnode *next;
};
typedef struct sllnode node;

void create(node *,int );
void display(node *);
void displayall(node *[]);
int len(node*);
int insertbypos(node *, int);
int delbypos(node*,int );
int reverse(node * );
int sort(node* );
int main()
{
  int n,choice,i,j,k,pos,ch;
  node *header[max];
  ch=0;k=0;
  for(i=0;i<max;i++){
  header[i]=(node*)malloc(sizeof(node));
  header[i]->next=NULL;

  }
  do
    {
  printf("Menu\n1.Create a linked list\n2.Display the linked list\n3.Insert a node\n4.Delete a node\n5.Reverse\n6.Sort\n7.Merge two linked lists\nEnter your choice: ");
  scanf("%d",&choice);
  switch(choice)
    {
    case 0:
      printf("Thank you\n");
      return 0;
      break;
    case 1:
      printf("Enter the number of links to be created\n");
      scanf("%d",&n);
      i=0;

      while(header[i]->next!=NULL)
        {

          i++;
          if(i==max-1)
            break;
        }
      if(header[i]->next!=NULL)
        i++;
      if(i==max)
        {
          printf("Error. Storage full. Delete one of the previous lists\n");
          displayall(header);


        }
      else
        {
      create(header[i],n);
      display(header[i]);
          }
    break;
    case 2:
      displayall(header);
      break;
    case 3:

      displayall(header);
      ch=0;
      do
        {
      scanf("%d",&i);
      i--;j=1;

      if(i>max-1)
            {printf("Error.List number too large. Creating a new list list within the limit\n");
              break;
            }
          if(header[i]->next==NULL)
            {
              printf("Error.List not found.\nCreate new List?\n1 for yes\n0 for no\n");
              scanf("%d",&j);

            }
        }while(j!=1);
      if(j==1 && i<max && header[i]->next==NULL)
        {
          i=k;
          for(;header[k]->next!=NULL  ;)
            {
              printf("%d",k);
              k++;
              i=k;
              if(k==max-1)
                break;

            }
        }
      k++;
      if(i >max-1 && header[i]->next!=NULL)
        {
          k=0;
          printf("Error.No space left.Delete one of the previous lists\n");
        }
      else
        {
      printf("%d",i);
      printf("Enter the position\n");
      scanf("%d",&pos);


      insertbypos(header[i],pos);
      display(header[i]);
      }
      break;
    case 4:
      displayall(header);
      printf("Enter the link number\n");
      scanf("%d",&i);
      i--;
      if(header[i]->next==NULL)
        printf("Error.List doesnt exist\n");
      else
        {
          printf("Enter the position\n");
          scanf("%d",&pos);
          delbypos(header[i],pos);
          display(header[i]);
        }
      break;
    case 5:
      displayall(header);
      printf("Select the link\n");
      scanf("%d",&i);
      i--;
      if(header[i]->next==NULL)
        printf("Error.List doesnt exist\n");
      else
        {
          reverse(header[i]);
          display(header[i]);
        }
      break;
    case 6:
      displayall(header);
      do{
      printf("Enter the list to be sorted\n");
      scanf("%d",&i);
        i--;
        if(i>max)
          printf("Error.List number beyond size\n");
        else
          {


        if(header[i]->next==NULL)
          printf("Error.List doesnt exist\n");
          }
      }while(header[i]->next==NULL);
      sort(header[i]);
      display(header[i]);
      break;
    case 7:
      break;
    default:
      printf("Error.Please retry");
    }
    }while(choice!=0);

  return 0;
}


void create(node * header , int l)
{
  int i=0,ll;
  node *temp, *curr;
  curr=header;
  for(i=0;i<l;i++)
    {

      temp=(node * )malloc(sizeof(node));

      printf("Enter the number\n");
      scanf("%d",&temp->data);
      temp->next=NULL;
      curr->next=temp;
      curr=temp;
    }
}

void display(node * header)
{
  node* curr,*temp;
  curr=header->next;
  printf(" List = [");
  while(curr!=NULL)
    {
      printf("%d",curr->data);
      curr=curr->next;
      if(curr!=NULL)
        printf(",");


    }
  printf("]\n");
}

int insertbypos(node * header, int pos)
{
  node * curr,*temp;
  int i=1;
  if(pos>0)
    {
  curr=header;
  while(i!=pos)
    {
      curr=curr->next;
      i++;
      if(curr==NULL && i<=pos-1)
        {
          printf("Error. Position greater  than size of list\n");
          return(0);
        }
    }
  temp=(node*)malloc(sizeof(node));
  temp->next=curr->next;
  curr->next=temp;
  printf("Enter the number\n");
  scanf("%d",&temp->data);

    }
  else
    {
      printf("Incorrect position.");
    }
  return 1;
}
int len(node * header)
{
  node* curr;
  int i=0;
  curr=header->next;
  while(curr!=NULL)
    {
      i++;
      curr=curr->next;
    }
return i;
}


int delbypos(node * header,int pos)
{
int l,count;
  node *curr,*temp;
  count=0;
  l=len(header);
  curr=header;

  if(l<pos)
    {
      printf("Error.Position is greater than the length of the list");
      return 0;

    }
  else
    {
      while(count<pos-1)
        {
          count++;
          curr=curr->next;
        }
      temp=curr->next;
      curr->next=temp->next;
      temp->next=NULL;
      free(temp);
    }
  return 1;
}
void displayall(node * header[])
{
       int j;
      printf("Linked Lists\n");
      for(j=0;j<max;j++)
        {
          if(header[j]->next!=NULL)
            {


          printf("%d",j+1);
          display(header[j]);
            }
        }
}

int reverse(node * header)
{
  node * prev,*curr,*temp;
  prev =NULL;
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
  l=len(header);
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
  return 0;
}
