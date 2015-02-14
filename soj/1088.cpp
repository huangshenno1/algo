#include <stdio.h>
#include <string.h>
#define N 11
void main()
{
    int i,n,e,p,q,flag;
    scanf("%d",&n);
    while (n!=0)
    {
        flag=1;
        p=1;
        if (n>0&&n<10)
            e=7;
        else if (n>9&&n<100)
            e=14;
        for (i=0;i<e;i++)
            p*=2;
        q=p;
        while (flag)
        {
            while (q>0)
            {
                q/=10;
                if (q==n)
                {
                    printf("%d\n",e);
                    flag=0;
                    break;
                }
            }
            e++;
            p*=2;
            q=p;
        }
        scanf("%d",&n);
    }
}