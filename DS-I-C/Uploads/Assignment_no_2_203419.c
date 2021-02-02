#include<stdio.h>
void acceptarray(int a,int b,int[a][b] );
void display(int r,int c,int m[r][c]);
int findn(int r,int c,int m[r][c]);
void fillsprse(int [][3],int n, int r , int c ,int m[r][c]);
void sprsedisp(int [][3],int n);
void st(int [][3],int ,int [][3]);
void ft(int [][3], int,int [][3]);
int main()
{
  int r,c,n,choice;
  do
    {
  printf("Enter the number of rows of the matrix\n");
  scanf("%d",&r);
  printf("Enter the number of columns of the matrix\n");
  scanf("%d",&c);
  int matrix[r][c];
  acceptarray(r,c,matrix);
  display(r,c,matrix);
  n=findn(r,c,matrix);
  int sprsem[n+1][3],spt[n+1][3];
  fillsprse(sprsem,n,r,c,matrix);
  sprsedisp(sprsem,n+1);
  printf("Menu:\n1.Simple Transpose\n2.Fast Transpose\n0.Exit\nEnter your choice\n");
  scanf("%d",&choice);
  switch(choice)
    {
    case 0:
      printf("Thank You\n");//
    break;

    case 1:
      st(sprsem,n+1,spt);
      printf("Simple Transpose:\n");
      sprsedisp(spt,n+1);
    break;

    case 2:
      ft(sprsem,n+1,spt);
      printf("Fast Transpose:\n");
      sprsedisp(spt,n+1);
    break;

    default:
      printf("Error.Please rery\n");
    }
    }while(choice!=0);
      return 0;
}
void ft(int m[][3], int n,int t[][3])
{

int rowterm[m[0][1]],startpos[m[0][1]],i,v;
  int numcols=m[0][0];
  int numrows=m[0][1];
  for(i=0;i<numrows;i++)
    {
      rowterm[i]=0;
    }
  startpos[0]=1;
  for(i=1;i<=n-1;i++)
    {
      v=m[i][1];
      rowterm[v]++;
    }
  for(i=1;i<numrows;i++)
    {
      startpos[i]=startpos[i-1]+rowterm[i-1];
    }
  t[0][0]=numrows;
  t[0][1]=numcols;
  t[0][2]=n-1;
  for(i=1;i<n;i++)
    {
      int j=m[i][1];
      t[startpos[j]][0]=m[i][1];
      t[startpos[j]][1]=m[i][0];
      t[startpos[j]][2]=m[i][2];
      startpos[j]++;
    }




}
void st(int m[][3],int n,int t [][3])
{
  int i,j,k;
  k=1;
  t[0][1]=m[0][0];
  t[0][0]=m[0][1];
  t[0][2]=m[0][2];
  for(i=0;i<m[0][1];i++)
    {
      for(j=1;j<n;j++)
        {
          if(m[j][1]==i)
            {
              t[k][0]=m[j][1];
              t[k][1]=m[j][0];
              t[k][2]=m[j][2];
              k++;

            }
        }
    }
}
void acceptarray(int r,int c,int m[r][c])
{
  int i,j;
  printf("Enter the Matrix\n");
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
          scanf("%d",&m[i][j]);
        }
    }
}

void display(int r,int c,int m[r][c])
{
  printf("Matrix Value:\n");
  int i,j;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
      printf("\n");
    }
}

int findn(int r,int c,int m[r][c])
{
  int i,j,n;
  n=0;
  for(i=0;i<c;i++)
    {
      for(j=0;j<c;j++)
        {
          if(m[i][j]!=0)
            {
              n++;

            }
        }
    }
  return n;
}

void fillsprse(int s[][3],int n, int r,int c,int m[r][c])
{
  int i,j,k;
  s[0][0]=r;
  s[0][1]=c;
  s[0][2]=n;
  k=1;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
          if(m[i][j]!=0)
            {
              s[k][0]=i;
              s[k][1]=j;
              s[k][2]=m[i][j];
              k++;
            }
        }
    }
}

void sprsedisp(int s[][3],int n)
{
  int i;
  printf("Sparse Matrix:\n");
  for(i=0;i<n;i++)
    {
      printf("%d\t%d\t%d\n",s[i][0],s[i][1],s[i][2]);
    }
}
