#include <stdio.h>

long long minimum;

void money(long long i,long long s,long long m,long long note[])
{
    if (s>=m&&s<minimum)
        minimum=s;
    if (i<0)
        return;
    else if (s>=m)
        return;
    else
    {
        money(i-1,s+note[i],m,note);
        money(i-1,s,m,note);
    }
}

int main()
{
    long long n,m;
    long long note[20];
    while (scanf("%lld%lld",&n,&m)==2)
    {
        minimum=1000000001;
        long long s=0;
        long long i;
        for (i=0;i<n;i++)
        {
            scanf("%lld",&note[i]);
            s+=note[i];
        }
        if (s<m)
            printf("-1\n");
        else if (s==m)
            printf("%d\n",n);
        else
        {
            money(n-1,0,m,note);
            printf("%d\n",minimum);
        }
    }
    return 0;
}