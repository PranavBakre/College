include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 1001
int main() {
    char kt[max],tc[max];
    int i=0,j=0,l,ctr=0;
    l=strlen(kt);
    while(kt[i]!='\0' && tc[j]!='\0')
    {
        if(kt[i]==tc[j])
        {
            i++;
            j++;
            ctr++;
        }
      else break;

    }
    if(ctr==l)
        printf("zabardast");
    else
        printf("lalala");
    return 0;
}
