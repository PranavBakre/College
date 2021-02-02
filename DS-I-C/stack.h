#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 1000
struct stack
{
  char data [max][max];
  int top;
};

typedef struct stack stack;
struct charstack
{
  char data[max];
  int top;
};
typedef struct charstack cstack;
//Check stack
int isemp(stack*);
int isfull(stack*);
//Stack operations
void push(stack* , char[]);
void pop(stack*,char*);
void display(stack*);
//Character Stack
int stackemp(cstack*);
int stackfull(cstack*);
void cpush(cstack*,char);
char cpop(cstack*);
void cdisplay(cstack*);

//Expression Conversion
void postin(stack*,char[]);
void postpre(stack*,char[]);

void prepost(stack*,char[]);
void prein(stack*,char[]);

void inpre(cstack*,char []);
void inpost(cstack*,char[]);

//Priority
int ICP(char ,int);
int ISP(char ,int);

//Definition
void push(stack* s, char elem[])
{
  s->top++;
  strcpy(s->data[s->top],elem);
}

void pop(stack* s,char * elemx)
{
  strcpy(elemx,s->data[s->top]);
  s->top--;

}

void display(stack *s)
{
  int i;
  for(i=s->top;i>-1;i--)
    {
      printf("%s\n",s->data[i]);
    }
}

void postin(stack *s,char elem[])
{
  int i;
  char opr[max],opnd[max],op1[max],op2[max],form[max];
            for(i=0;elem[i]!='\0';i++)
            {
              if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
                {
                  strcpy(form,"(");
                  opr[0]=elem[i];
                  opr[1]='\0';
                  pop(s,op1);
                  pop(s,op2);
                  strcat(form,op2);
                  strcat(form,opr);
                  strcat(form,op1);
                  strcat(form,")");
                  push(s,form);


                }
              else
                {
                  opnd[0]=elem[i];
                  opnd[1]='\0';
                  push(s,opnd);
                }
            }
}
void postpre(stack* s,char elem[])
{
  int i;
  char opr[max],opnd[max],op1[max],op2[max],form[max];
            for(i=0;elem[i]!='\0';i++)
            {
              if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
                {
                  strcpy(form,"(");
                  opr[0]=elem[i];
                  opr[1]='\0';
                  pop(s,op1);
                  pop(s,op2);
                  strcat(form,opr);
                  strcat(form,op2);
                  strcat(form,op1);
                  strcat(form,")");
                  push(s,form);


                }
              else
                {
                  opnd[0]=elem[i];
                  opnd[1]='\0';
                  push(s,opnd);
                }
            }
}
void prepost(stack* s,char elem[])
{
    int i,l=strlen(elem);
  char opr[max],opnd[max],op1[max],op2[max],form[max];
            for(i=l;i>=0;i--)
            {
              if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
                {
                  strcpy(form,"(");
                  opr[0]=elem[i];
                  opr[1]='\0';
                  pop(s,op2);
                  pop(s,op1);
                  strcat(form,op2);
                  strcat(form,op1);
                  strcat(form,opr);
                  strcat(form,")");
                  push(s,form);


                }
              else
                {
                  opnd[0]=elem[i];
                  opnd[1]='\0';
                  push(s,opnd);
                }
            }
}
void prein(stack *s, char elem[])
{
    int i,l=strlen(elem);
  char opr[max],opnd[max],op1[max],op2[max],form[max];
            for(i=l;i>=0;i--)
            {
              if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
                {
                  strcpy(form,"(");
                  opr[0]=elem[i];
                  opr[1]='\0';
                  pop(s,op2);
                  pop(s,op1);
                  strcat(form,op2);
                  strcat(form,opr);
                  strcat(form,op1);
                  strcat(form,")");
                  push(s,form);


                }
              else
                {
                  opnd[0]=elem[i];
                  opnd[1]='\0';
                  push(s,opnd);
                }
            }
}

void inpre(cstack *s ,char elem[])
{

  int i,j=0,k,l,m;
  char array[max];
  l=strlen(elem);
  for(i=l;i>=0;i--)
    {

      if(isalnum(elem[i]))
        {

          array[j]=elem[i];
          j++;
        }
      else if(elem[i]=='\0')
        {

          while(s->top>=0)
            {
              array[j]=cpop(s);
              j++;

            }
        }
      else if(elem[i]=='(')
        {
          for(m=i;elem[m]!=')';m++)
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
  for(k=j;k>=0;k--)
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
