#include <stdio.h>
struct sparse
  {
      int row,col,val;
  };
typedef struct sparse spm;
void acceptarray(int r, int c,int m[r][c]);
void display(int r, int c,int m[r][c]);
void spmdisp(spm[], int );


int main()
  {
    int r,c,n,i,j,k;

    n=0;
    k=1;
    printf("Enter the number of rows in th matrix\n");
    scanf("%d",&r);
    printf("Enter the number of columns in the matrix\n");
    scanf("%d",&c);
    int matrix[r][c];
    acceptarray(r,c,matrix);
    printf("The matrix is \n");
    for(i=0;i<r;i++)
      {
        for(j=0;j<c ;j++)
          {
            printf("%d\t",matrix[i][j]);
          }
        printf("\n");
      }
    for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
          {
            if(matrix[i][j]!=0)
              n++;
          }
      }
    spm spmatrix[n+1];
    spmatrix[0].row=r;
    spmatrix[0].col=c;
    spmatrix[0].val=n;
    for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
          {
              if(matrix[i][j]!=0)
              {
                spmatrix[k].row=i;
                spmatrix[k].col=j;
                spmatrix[k].val=matrix[i][j];
                k++;
          }}
      }
    printf("\n\n");
    spmdisp(spmatrix,n+1);

    printf("Simple transpose\n");
    int temp[r][c];
    for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
          {
            temp[j][i]=matrix[i][j];
          }
      }

        for(i=0;i<r;i++)
      {
        for(j=0;j<c ;j++)
          {
            printf("%d\t",temp[i][j]);
          }
        printf("\n");
      }
    return 0;
  }

void acceptarray(int r,int c,int m[r][c])
  {
    int i,j;
    printf("Enter the elements in the matrix\n");
    for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
          {
            scanf("%d",&m[i][j]);
          }
      }
  }
void display(int r, int c,int m[r][c])
{

}
void spmdisp(spm s[],int n)
  {
    int k;
    for(k=0;k<n;k++)
      {
        printf("%d\t%d\t%d\n",s[k].row,s[k].col,s[k].val);
      }
  }
