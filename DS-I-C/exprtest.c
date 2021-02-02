/* main.c
 *
 * Copyright 2018 Unknown
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//*********************************
// NAME: Pranav Shrikant Bakre
// ROLL NO. 203419
// SUBJECT: Data structures1
// Assignment No 4
// ********************************
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

int main()
{
  stack s;
  cstack cs;
  s.top=-1;
  cs.top=-1;
  char elem[max],elemx[max];
  int choice,check,i;


  /*do
    {
  printf("Menu\n0.Exit\n1.Push an element into a stack\n2.Pop an element from the stack\n3.Display all elements\nEnter your choice\n");
  scanf("%d",&choice);
  switch(choice)
    {
    case 0:
      printf("Thank You \n");
      return 0;
      break;
    case 1:
      printf("Enter the string\n");
      scanf("%s",elem);
      check=isfull(&s);
      if(check==1)
        {
          printf("Error.Stack full\n");
        }
      else
        {
          push(&s,elem);
        }
      break;
    case 2:
      check=isemp(&s);
      if(check==1)
        {
          printf("Error.Stack empty\n");
        }
      else
        {
          pop(&s,elemx);
          printf("Popped ELement: %s\n",elemx);
        }
      break;
    case 3:
      display(&s);
      break;
    default:
      printf("Error.Please retry\n");
    }
    }while(choice!=0);*/
  do
    {
      printf("Menu\n0.Exit\n1.Postfix to Infix form\n2.Postfix to prefix\n3.Prefix to Postfix\n4.Prefix to Infix\n5.Infix to Prefix\n6.Infix to Postfix\nEnter your choice\n");
      scanf("%d",&choice);
      switch(choice)
        {
        case 0:
          printf("Thank you\n");
          return 0;
          break;
        case 1://Postfix to infix
          printf("Enter the expression\n");
          scanf("%s",elem);
          postin(&s,elem);
          pop(&s,elemx);
          printf("Converted Expression: %s\n",elemx);
          break;
        case 2://Postfix to prefix
          printf("Enter the expression\n");
          scanf("%s",elem);
          postpre(&s,elem);
          pop(&s,elemx);
          printf("Converted Expression: %s\n",elemx);
          break;
        case 3://Prefix to Postfix
          printf("Enter the expression\n");
          scanf("%s",elem);
          prepost(&s,elem);
          pop(&s,elemx);
          printf("Converted Expression: %s\n",elemx);
          break;
        case 4://Prefix to Infix
          printf("Enter the expression\n");
          scanf("%s",elem);
          prein(&s,elem);
          pop(&s,elemx);
          printf("Converted Expression: %s\n",elemx);
          break;
        case 5://Infix to Prefix
          printf("Enter the expression\n");
          scanf("%s",elem);
          inpre(&cs,elem);
         break;
        case 6:
          printf("Enter the expression\n");
          scanf("%s",elem);
          inpost(&cs,elem);
          break;
        default:
          printf("Error.Please retry\n");
        }
    }while(choice!=0);

  return 0;

}



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
                  pop(s,op1);//Operand 1
                  pop(s,op2);//Operand 2
                  strcat(form,op2);//Expression start
                  strcat(form,opr);
                  strcat(form,op1);
                  strcat(form,")");//Expression end
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
                  pop(s,op1);//Operand 1
                  pop(s,op2);//Operand 2
                  strcat(form,opr);//Expression start
                  strcat(form,op2);
                  strcat(form,op1);
                  strcat(form,")");//Expression end
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
                  strcat(form,op2);//Expression start
                  strcat(form,op1);
                  strcat(form,opr);
                  strcat(form,")");//Expression end
                  push(s,form);


                }
              else//Push operand into stack
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
                  pop(s,op2);//Operand 2
                  pop(s,op1);//operand 1
                  strcat(form,op2);//Expression start
                  strcat(form,opr);
                  strcat(form,op1);
                  strcat(form,")");//Operand end
                  push(s,form);


                }
              else//Push operand into stack
                {
                  opnd[0]=elem[i];
                  opnd[1]='\0';
                  push(s,opnd);
                }
            }
}

void inpre(cstack *s ,char elem[])//Infix to prefix
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
            for(k=j;k>=0;k--)
    {

      printf("%c",array[k]);
    }
printf("\n");
        }
      else if(elem[i]=='\0')
        {

          while(s->top>=0)
            {
              array[j]=cpop(s);
              j++;
       for(k=j;k>=0;k--)
    {

      printf("%c",array[k]);
    }printf("\n");
            }
        }
      else if(elem[i]=='(')
        {
          for(m=i;elem[m]!=')';m++)
            {
              array[j]=cpop(s);
              j++;
            for(k=j;k>=0;k--)
    {

      printf("%c",array[k]);
    }printf("\n");
              }
        }
      else if(elem[i]=='+'||elem[i]=='-'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
        {

          while(ISP(s->data[s->top],0)>=ICP(elem[i],0))
            {
              array[j]=cpop(s);
              j++;
                   for(k=j;k>=0;k--)
    {

      printf("%c",array[k]);
    } printf("\n");}
           cpush(s,elem[i]);printf("stack: ");cdisplay(s);;
        }
      else
        {

           cpush(s,elem[i]);printf("stack: ");cdisplay(s);;
        }
    }
  while(s->top>=0)
    {

      array[j]=cpop(s);
      j++;
                 for(k=j;k>=0;k--){

      printf("%c",array[k]);
    }printf("\n");
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
       cpush(s,elem[i]);printf("stack: ");cdisplay(s);;
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
         cpush(s,elem[i]);printf("stack: ");cdisplay(s);;



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
int ICP(char ch,int n)//Incoming priority
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

int ISP(char ch,int n)//In stack priority
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

  for(i=0;i<s->top;i++)
    {
      printf("%c",s->data[i]);
    }
  printf("\n");
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
