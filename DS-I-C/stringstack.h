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

//Check stack
int isemp(stack*);
int isfull(stack*);
//Stack operations
void push(stack* , char[]);
void pop(stack*,char*);
void display(stack*);

//Expression Conversion
void postin(stack*,char[]);
void postpre(stack*,char[]);

void prepost(stack*,char[]);
void prein(stack*,char[]);

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

int isfull(stack* s)
{
  if(s->top==max-1)
    return 0;
  else
    return 1;
}
int isemp(stack* s)
{
  if(s->top==-1)
    return 0;
  else
    {
      return 1;
    }
}
