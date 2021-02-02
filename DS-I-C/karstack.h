#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 1000

struct charstack
{
  char data[max];
  int top;
};
typedef struct charstack cstack;
//Character Stack
int stackemp(cstack*);
int stackfull(cstack*);
void cpush(cstack*,char);
char cpop(cstack*);
void cdisplay(cstack*);


void inpre(cstack*,char []);
void inpost(cstack*,char[]);

//Priority
int ICP(char ,int);
int ISP(char ,int);

void inpre(cstack *s ,char elem[])
{

  int i,j=0,k,l,m;
  char array[max];
  l=strlen(elem);
  for(i=l-1;i>=0;i--)
    {

      if(isalnum(elem[i]))
        {

          array[j]=elem[i];
          j++;
        }

      else if(elem[i]=='(')
        {
          while(s->data[s->top]!=')')
            {
              array[j]=cpop(s);
              j++;
            }
        }
      else if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
        {

          while(ISP(s->data[s->top],0)>=ICP(elem[i],0))
            {
              array[j]=cpop(s);
              j++;
            }
          cpush(s,elem[i]);
        }
      else
        {

          cpush(s,elem[i]);
        }
    }
  while(s->top>=0)
    {

      array[j]=cpop(s);
      j++;
    }
  printf("OUTPUT: ");
  for(k=j-1;k>=0;k--)
    {
      if(array[k]!=')')
      printf("%c",array[k]);
    }
  printf("\n");
}

void inpost(cstack* s, char elem[])
{
  int i,j=0,k,l,m;
  char array[max];
  for(i=0;elem[i]!='\0';i++)
{
  if(elem[i]=='(')
    {
      cpush(s,elem[i]);
    }
  else if(isalnum(elem[i]))
    {
      array[j]=elem[i];
      j++;
    }
  else if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
    {

      while(ICP(elem[i],1)<ISP(s->data[s->top],1))
          { array[j]=cpop(s);
        j++;
      }
        cpush(s,elem[i]);



    }
  else if(elem[i]==')')
        {
          while(s->data[s->top]!='(')
            {
              array[j]=cpop(s);
              j++;
            }
          cpop(s);
        }
        else
        {

          array[j]=cpop(s);
      j++;
        }
}
  while(stackemp(s)!=0)
    {
      array[j]=cpop(s);
      j++;
    }
  printf("OUTPUT: ");
  array[j]='\0';
  printf("%s\n",array);


}
//Priority
int ICP(char ch,int n)
{
switch(ch)
    {
    case '+':
    case '-':
      return 2;
      break;
    case '*':
    case '/':
      return 3;
      break;
    case '(':
    case ')':
      return 4;
      break;
    case '^':
      if(n==0)
      return 5;
      else
      return 6;
    default:
      return -1;
    }
}

int ISP(char ch,int n)
{
switch(ch)
    {
    case '+':
    case '-':
      return 2;
      break;
    case '*':
    case '/':
      return 3;
      break;
    case '(':
    case ')':
      return 0;
      break;
    case '^':
      if(n==0)
      return 6;
      else
      return 5;
    default:
      return -1;
    }
}
//Character Stack
void cdisplay(cstack* s)
{
  int i;
  for(i=s->top;i>-1;i--)
    {
      printf("%c\n",s->data[i]);
    }
}
char cpop(cstack* s)
{
  char temp=s->data[s->top];
  s->top--;
  return temp;
}
void cpush(cstack* s,char elem)
{
  s->top++;
  s->data[s->top]=elem;
}
int stackfull(cstack* s)
{
  if(s->top==max-1)
    return 0;
  else
    return 1;
}
int stackemp(cstack* s)
{
  if(s->top==-1)
    return 0;
  else
    {
      return 1;
    }
}
