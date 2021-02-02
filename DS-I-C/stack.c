//*********************************
// NAME: Pranav Shrikant Bakre
// ROLL NO. 203419
// SUBJECT: Data structures1
// Assignment No $
// ********************************
#include"stringstack.h"
#include"karstack.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
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

