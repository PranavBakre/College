#include<stdio.h>
void accept(char*);//Accept the string
void display(char*);//Display the string
int len(char *);//Calculate the length of the string
void copy(char *,char *);//Copy the data of one string to another
void concat(char*,char*);//Concatenate two strings
void rev(char *);//Reverse a string
int pal(char *);//Check palindrome
int equal(char*,char *);//Compare two strings
int sub(char*,char*);//Check substring
int main()
	{
	char string1[100],string2[100],string3[100];
	int l,choice,t,eq,palc,m;
	do
	{
	printf("Menu\n0.Exit\n1.Length of the string\n2.Copy the string\n3.Concatenate the string\n4.Reverse a string\n5.Palindrome\n6.Equal\n7.Substring\nEnter 	your choice\n");
	scanf("%d",&choice);
	switch(choice)
		{
		case 0://Exit
			printf("Thank You\n");
		break;
		case 1://Length of the string
			accept(string1);
			l=len(string1);
			printf("Length of the string is %d\n", l);
		break;
		case 2://Copy one string to another
			accept(string1);
			copy(string1,string2);
			printf("String copied. \n");
			display(string2);
		break;
		case 3://Concatenate two strings
			accept(string1);
			accept(string2);
			concat(string1,string2);
			printf("Concatenated String\n");
			display(string1);
		break;
		case 4://Reverse a string
			accept(string1);
			rev(string1);
			printf("Reversed String: \n");
			display(string1);
		break;
		case 5://Check palindrome
      accept(string1);
			palc=pal(string1);
      if(palc==1)
          printf("String is a Palindrome\n");
        else
          printf("String is not palindrome\n");
		break;

    case 6://Compare two strings
      accept(string1);
      accept(string2);
      eq=equal(string1,string2);
      if(eq==0)
        printf("%s is equal to %s\n",string1,string2);
      if(eq==1)
        printf("%s is greater than %s\n",string1,string2);
      if(eq==-1)
        printf("%s is lesser than %s\n",string1,string2);
      break;

    case 7://Ceck substrings
      accept(string1);
      accept(string2);
      m=sub(string1,string2);
        if(m>0)
          printf("%s is  substring of %s and is repeated %d  times\n",string2,string1,m);
        else
          printf("%s is not a substring of %s\n",string2,string1);

      break;
		default:
			printf("Error.Please retry\n");
		}
	}while(choice!=0);
}

int sub(char *str1, char *str2)//Check substring using pointers
{
  char *str3,*str4;
  str3=str1;
  str4=str2;
  int i,j,l,m,cn;
  int ctr=m=cn=0;
  l=len(str2);
  while(*str1!='\0')
    {
  while(*str2!='\0' && *str1!='\0')
    {
      if(*str1==*str2)
        {
          ctr++;
          str2++;
          str1++;
        }
      else
        {
          str2=str4;
          ctr=0;
          cn++;
          if(cn==1 &&str1 >=str3+len(str2)-1)//Decrement main string for 1 bit overlap
            {

                 str1-=len(str2)-1;
            }
          else
            {
              str1++;
            }

        }

    }
      cn=0;
  if(ctr==l)
    m++;
      str2=str4;
      ctr=0;
  }
return m;

}
int equal(char *str,char *str2)
{

  int c;

  if(*str=='\0' && *str2!='\0')//Check if string 1 is null
    c=-1;
  else if(*str!='\0' && *str2=='\0')//Check if string 2 is null
    c=1;
  else
    {
  if(*str>*str2)//Check if string 2 is greater than string 2
    c=1;
  else if(*str<*str2)//Check if string 2 is greater
    c=-1;
  else//Check if characters are equal
    {

      str++;
      str2++;
      if(*str!='\0' || *str2!= '\0')
      c=equal(str,str2);
        if(*str=='\0' && *str2== '\0')
        {
          c=0;
        }

    }
    }

return c;
}
int pal(char * str)
	{
		int i,j,count;
		i=j=count=0;
		char str2[100];
		while(*str!='\0')
			{
				str2[i]=*str;//Assignment of the string into a temp
				str++;i++;
			}
		str--;
		while(j<i)
			{
				if(*str==str2[j])
					count++;
				str--;j++;
			}
		if(count==i)
			return 1;
		else
			return 0;
	}
void accept(char *str)
	{
		printf("Enter the string\n");
		scanf("%s",str);
	}
void display(char * str)
	{
		printf("%s\n", str);
	}
void concat(char* dest,char* src)
	{
		while(*dest!='\0')
		{
			dest++;
		}
		while(*src!='\0')//Concatnating the string
		{
			*dest=*src;
			dest++;
			src++;
		}
		*dest='\0';
	}
void rev(char *str)
	{
		char strr[100];
		int i,j;
		i=j=0;
		while(*str!='\0')//Assignment to a temporary string
		{
			strr[i]=*str;
			str++;
			i++;
		}
		str--;
		while(j<i)//Reversing the string
		{
			*str=strr[j];
			j++;
			str--;
		}
	}
void copy(char *src, char *dest)
	{
		while(*src!='\0')
		{
			*dest=*src;
			src++;
			dest++;
		}
    *dest='\0';
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
/*
 *
[pranav@pranav C]$ gcc str2.c
[pranav@pranav C]$ ./a.out
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
1
Enter the string
hello\123
Length of the string is 9
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
2
Enter the string
hellonearth
String copied.
hellonearth
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
3
Enter the string
Hello
Enter the string
_world
Concatenated String
Hello_world
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
4
Enter the string
pandemonium
Reversed String:
muinomednap
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
5
Enter the string
madame
String is not palindrome
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
5
Enter the string
madam
String is a Palindrome
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
6
Enter the string
hello
Enter the string
hello
hello is equal to hello
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
6
Enter the string
hello
Enter the string
hell
hello is greater than hell
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
6
Enter the string
bell
Enter the string
dell
bell is lesser than dell
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
7
Enter the string
banana
Enter the string
ban
ban is  substring of banana and is repeated 1  times
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
7
Enter the string
banana
Enter the string
ana
ana is  substring of banana and is repeated 2  times
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
7
Enter the string
band
Enter the string
and
and is  substring of band and is repeated 1  times
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
102
Error.Please retry
Menu
0.Exit
1.Length of the string
2.Copy the string
3.Concatenate the string
4.Reverse a string
5.Palindrome
6.Equal
7.Substring
Enter 	your choice
0
Thank You
[pranav@pranav C]$

 * */
