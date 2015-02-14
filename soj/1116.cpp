#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
int back(int n)
{
    int i=0,s;
    char a[N];
    for(;;)
    {
        if (n==0)
            break;
        a[i++]=n%10+'0';
        n=n/10;
    }
    a[i]=0;
    s=atoi(a);
    return s;
}
int isback(int n)
{
    int i=0,l,flag=1;
    char a[N];
    for(;;)
    {
        if (n==0)
            break;
        a[i++]=n%10+'0';
        n=n/10;
    }
    a[i]=0;
    l=strlen(a);
    for (i=0;i<l/2;i++)
        if (a[i]!=a[l-i-1])
            flag=0;
    return flag;
}
void main()
{
    int L,M;
    int i,count,flag;
    scanf("%d",&L);
    for (i=0;i<L;i++)
    {
        count=0;
        flag=1;
        scanf("%d",&M);
        while (!isback(M))
        {
            if (count==8)
            {
                flag=0;
                break;
            }
            M=M+back(M);
            count++;
        }
        if (flag)
            printf("%d\n",count);
        else printf("0\n");
    }
}
    

