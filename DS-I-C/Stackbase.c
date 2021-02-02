#include<stdio.h>
# define max 100
struct stack
{
  char data[max];
  int top;
};
typedef struct stack stack;

int stackemp(stack*);
int stackfull(stack*);
void push(stack*,char);
char pop(stack*);
void display(stack*);

int main()
{
  int choice,emp;
  char elem,elemt;
  stack s;
  s.top=-1;
  do
    {
  printf("Menu\n0.Exit\n1.Push element into the stack\n2.Pop an element from the stack\n3.Display the stack elements\nEnter your choice\n");
  scanf("%d",&choice);
  switch(choice)
    {
    case 0:
      printf("Thank You\n");
      return 0;
      break;
    case 1:

      printf("Enter the elem\n");
      scanf(" %c",&elem);
      emp=stackfull(&s);
      if(emp==0)
        printf("Error.Stack full");
      else
        {
          push(&s,elem);
        }
      break;
    case 2:
      if(stackemp(&s)==0)
        printf("Error.Stack Empty\n");
      else
        {
          elemt=pop(&s);
          printf("Deleted element:\t%c\n",elemt);
        }
      break;
    case 3:
      printf("Stack\n");
      display(&s);
      break;
    default:
      printf("Error.Wrong choice\n");
    }
    }while(choice!=0);
  return 0;
}
void display(stack* s)
{
  int i;
  for(i=s->top;i>-1;i--)
    {
      printf("%c\n",s->data[i]);
    }
}
char pop(stack* s)
{
  char temp=s->data[s->top];
  s->top--;
  return temp;
}
void push(stack* s,char elem)
{
  s->top++;
  s->data[s->top]=elem;
}
int stackfull(stack* s)
{
  if(s->top==max-1)
    return 0;
  else
    return 1;
}
int stackemp(stack* s)
{
  if(s->top==-1)
    return 0;
  else
    {
      return 1;
    }
}
