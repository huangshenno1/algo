#include <stdio.h>
#include <math.h>

long long GCD(long long a,long long b)
{
    if (a<b)
    {
        long long t=a;
        a=b;
        b=t;
    }
    long long r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    long long g,l;
    while (scanf("%lld%lld",&g,&l)==2)
    {
        long long s,a,b;
        s=l/g;
        for (long long i=(long long)sqrt((long double)s);i>0;i--)
        {
            if (!(s%i)&&GCD(i,s/i)==1)
            {
                a=i*g;
                b=s/i*g;
                printf("%lld %lld\n",a,b);
                break;
            }
        }
    }
    return 0;
}