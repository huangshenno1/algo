#include <stdio.h>
#include <string.h>
#define N 110
void main()
{
    char ch[N];
    int i=0,l;
    char t;
    while (scanf("%c",&ch[i])==1)
    {
        if (ch[i]!=' '&&ch[i]!='\t')
            i++;
        else
            break;
    }
    l=i;
    for (i=l-1;i>=0;i--)
    {
        printf("%c",ch[i]);
    }
}