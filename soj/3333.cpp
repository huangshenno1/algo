#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
        long long r=(n+m)%m;
        long long d=n/m;
        long long s1=m*(m-1)/2;
        long long s2=r*(r+1)/2;
        long long s=s1*d+s2;
        printf("%lld\n",s);
    }
    return 0;
}