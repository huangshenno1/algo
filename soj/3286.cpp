#include <stdio.h>

int max;

void f(long long n,int step)
{
    if (n==1)
    {
        if (step>max)
            max=step;
        return;
    }
    if (n&1)
        f(3*n+1,step+1);
    else f(n/2,step+1);
}

int main()
{
    int t;
    long long a,b;
    scanf("%d",&t);
    while (t--)
    {
        max=0;
        scanf("%lld %lld",&a,&b);
        for (int i=a;i<=b;i++)
            f(i,0);
        printf("%d\n",max);
    }
    return 0;
}