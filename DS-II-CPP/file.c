#include<stdio.h>

int main() {
    FILE *fp;
    fp=fopen("test.txt","r");
    char ch;
    int ctr=0;
   /*  do {
        ch=fgetc(fp);
        if(ch=='\"') {
            ctr++;
        }
        if (ctr%2!=0 && ch!='\"') {
            printf("%c",ch);
        }
        else if (ch=='"' && ctr%2==0)
        {
            printf("\n");
        }
        
    }while(ch!=EOF);
*/
    fseek(fp,0,SEEK_END);
    int length=ftell(fp);
    fseek(fp,0,SEEK_SET);

     for(int i=0;i<length;i++) {
        ch=fgetc(fp);
        
        if(ch=='\"'){
            ch=fgetc(fp);
            for(;ch!='\"';ch=fgetc(fp)){
            printf("%c",ch);
            i++;
            }
        }

        if (ch=='\"')
            printf("\n");

    }

    return 0;
}