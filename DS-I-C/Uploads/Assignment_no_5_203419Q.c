#include<stdio.h>
#include<string.h>
#define namax 500
#define max 10
struct order
{
  char name[namax];
  int oid;
  char address[namax];
  char ordername[namax];
  long long mobno;
};
typedef struct order order;
struct pizzaparlour
{
  order order[max];
  int r,f;
};
typedef struct pizzaparlour pp;
//Pizza parlour functions
void enqueue(pp*,order);
void dequeue(pp*,order*);
void display(pp);
int isfull(pp);
int isemp(pp);
//Order functions
void addorder(order*);
void disorder(order);
int main()
{
  int choice;
  pp p1;
  order o1;
  p1.f=-1;
  p1.r=-1;
  do
    {
  printf("Menu\n0.Exit\n1.Add order\n2.Delete Order\n3.Display the remaining orders\nEnter your choice\n");
  scanf("%d",&choice);
  switch(choice)
    {
    case 0:
      return 0;
    case 1:
      addorder(&o1);
      if(isfull(p1)==0)
        enqueue(&p1,o1);
      else
        {
          printf("Error.Queue full\n");
        }
      break;
    case 2:
      if(isemp(p1)==0)
        {
        dequeue(&p1,&o1);
          printf("Order removed: \n");
        disorder(o1);
          printf("\n");

        }
          else
        {
          printf("Error.Queue Empty\n");
        }
      break;
    case 3:
      if(isemp(p1)==1)
        printf("Queue is empty\n");
      else
      display(p1);
      break;
    default:
      printf("Error.Please retry\n");
    }
}while(choice!=0);
  return 0;
}


//PizzaParlour
int isemp(pp p)
{
  if(p.f==p.r)
    return 1;
  return 0;
}
int isfull(pp p)
{
  if(p.r==max-1)
    return 1;
  return 0;
}
void enqueue(pp* p1,order o1)
{
  p1->r++;
  p1->order[p1->r]=o1;
  p1->order[p1->r].oid=p1->r+1;


}
void dequeue(pp* p2,order* o2)
{

  *o2=p2->order[++p2->f];
}

void display(pp p)
{
  int i;
for(i=p.f+1;i<=p.r;i++)
    {
      disorder(p.order[i]);
    }
}
//Order
void addorder(order * o)
{
  printf("Enter the name\n");
  scanf("%s",o->name);
  printf("Enter the mobile number\n");
  scanf("%Ld",&o->mobno);
  printf("Enter the order name\n");
  scanf("%s",o->ordername);

  printf("Enter the address\n");
  scanf("%s",o->address);
}

void disorder(order o)
{
  printf("Name: \t%s\nMobile Number: \t%Ld\nOrder Number: \t%d\nOrder Name: \t%s\nAddress: \t%s\n",o.name,o.mobno,o.oid,o.ordername,o.address);
}
