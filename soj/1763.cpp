#include <stdio.h>

int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main()
{
    int n;
    int i;
    while (scanf("%d",&n)==1)
    {
        if (n<0)
            break;
        if (n==0)
            printf("NO\n");
        else
        {
            for (i=9;i>=0;i--)
            {
                if (n>=fac[i])
                    n-=fac[i];
                if (n==0)
                    break;
            }
            if (n==0)
                printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}