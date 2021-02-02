/*
 ============================================================================
 Name        : stringreplace.c
 Author      :Pranav Bakre
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include<stdio.h>
#include<string.h>
void accept(char *);
void display(char*);
int len(char*);
void sub(char*,char*,char*);
//int substring(char[], char [] ,int[]);
int main()
{
  char str[100],str2[100],str3[100];
  int i,pos[100];
  for(i=0;i<100;i++)
    {
      pos[i]=0;
    }
  printf("Enter the main string\n");
  accept(str);
  printf("Enter the string to be detected\n");
  accept(str2);

  printf("Enter the string to be replaced\n");
  accept(str3);
  sub(str,str2,str3);
  printf("%s",str);
  return 0;
}
int len(char * strp)
	{
		int i=0;
		while(*strp!='\0')
			{
			strp++;
			i++;
			}

	return i;
	}
void accept(char * str)
{

  scanf("%s",str);
}
/*
int substring(char  str[],char  str2[],int pos[])
{
  int ctr=0,l,m=0;

  int i=0,j=0;
  l=strlen(str2);
  while(str[i]!='\0')
    {
      while(str[i]!='\0' && str2[j]!='\0')
        {
          if(str[i]==str2[j])
            {
              ctr++;
              i++;
              j++;
            }
          else

            {
              j=0;
              i++;
              ctr=0;
            }
          }

      if(ctr==l)
        {
          m++;
          ctr=0;
          j=0;
        }   }
  return m;
}
 */
void sub(char *str1, char *str2,char * str6)//Check substring using pointers
{
  char *str3,*str4,*str5,*str7,*str8;
  str8=str6;
  str3=str1;
  str4=str2;
int i,j,l,l2,m,cn;
  int ctr=m=cn=0;
  l=len(str2);
  l2=len(str6);
  while(*str1!='\0')
    {
  while(*str2!='\0' && *str1!='\0')
    {
      if(*str1==*str2)
        {
          ctr++;
          if(ctr==1)
            str7=str1;
          str2++;
          str1++;
        }
      else
        {
          str2=str4;
          ctr=0;
          cn++;
          if(cn==1 && str1!=str3)
            {

                 str1--;

            }
          else
            {
              str1++;
            }

        }

    }
      cn=0;
  if(ctr==l){
    m++;
    i=l2-l;
      str5=str1;
      cn=0;
      if(i>=0)
      {      while(*str1!='\0')
        {
          str1++;
        }
      while(str1!=str5-1)
        {

            *(str1+i)=*str1;
          str1--;
      }

      }
      else
          {
           while(*str1!='\0')
              {
                *(str1+i)=*str1;
                str1++;
              }
            *(str1+i)='\0';
          }
      while(str1!=str7)
        {
          str1--;
        }
              str6=str8;
      while(*str6!='\0')
        {
          *str1=*str6;
          str1++;
          str6++;
        }}
      str2=str4;
      ctr=0;
}
  if(m==0)
    printf("%s is not a substring of %s\n",str4,str3);
}
