#include <stdio.h>

int main()
{
    int n;
    int s,i,q;
    while (scanf("%d",&n)==1)
    {
        s=n;
        q=n/2;
        for (i=1;i<=q;i++)
        {
            if (n%i==0)
                s+=i;
        }
        printf("%d\n",s);
    }
    return 0;
}